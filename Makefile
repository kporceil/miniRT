NAME := miniRT

TEST := no

override SRCDIR := srcs/

ifeq ($(TEST), yes)
override BUILDDIR := .build/test/$(MODE)/
endif
ifeq ($(TEST), no)
override BUILDDIR := .build/$(MODE)/
endif

override FLAGFILE := .build/.compile_flags

override OBJDIR := $(addprefix $(BUILDDIR), objs/)

override DEPDIR := $(addprefix $(BUILDDIR), deps/)

ifeq (yes, $(TEST))
MAIN := test_main
TEST_BASENAME :=  $(addprefix test/, $(addprefix tuples/, create_tests add_tests substract_tests negate_tests scalar_tests magnitude_tests normalizing_tests dot_product_tests cross_product_tests) \
					$(addprefix color/, create_tests add_tests substract_tests scalar_tests mult_tests) \
					$(addprefix canvas/, create_tests write_pixel_tests ppm_tests) \
					$(addprefix matrix/, create_tests comparison_tests mult_tests transposing_tests determinant_tests submatrix_tests minors_tests cofactor_tests larger_determinant_tests inverting_tests translation_tests scaling_tests rotation_tests shearing_tests chaining_tests view_transformation_tests) \
					$(addprefix ray/, create_tests position_tests sphere_intersect_tests hit_tests transform_tests) \
					$(addprefix light/, normal_tests reflection_tests point_light_tests material_tests phong_tests) \
					$(addprefix world/, create_tests intersect_tests precomps_tests shading_tests) \
					$(addprefix camera/, create_tests ray_tests render_tests) \
					$(addprefix plane/, intersect_tests) \
					$(addprefix shadow/, in_shadow_tests is_shadowed_tests render_shadow_tests) \
					$(addprefix patterns/, striped_pattern_tests transform_pattern_tests ring_pattern_tests gradient_pattern_tests checker_pattern_tests) \
					$(addprefix reflect/, precompute_reflect_tests reflection_tests))

endif
ifeq (no, $(TEST))
MAIN := tmp_main
TEST_BASENAME :=
endif

BASENAME := $(MAIN) \
			$(addprefix tuples/, point vector add substract negate scalar magnitude normalize dot_product cross_product) \
			$(addprefix color/, color add substract scalar mult) \
			$(addprefix canvas/, canva write_pixel tmp_canva_to_ppm) \
			$(addprefix matrix/, create compare mult identity transposing determinant submatrix minors cofactor is_invertible invert translation scaling rotation shearing view_transformation shape_set_matrix) \
			$(addprefix ray/, create position intersect hit transform precompute) \
			$(addprefix spheres/, create intersect) \
			$(addprefix light/, normal reflect point_light material phong shade_hit color_at) \
			$(addprefix world/, create intersect) \
			$(addprefix camera/, create ray_for_pixel render) \
			$(addprefix shadow/, is_shadowed) \
			$(addprefix plane/, plane intersect) \
			$(addprefix patterns/, pattern_at pattern_at_object) \
			$(addprefix reflect/, reflected_color) \
			$(addprefix render_mlx/, display_mlx) \
			$(TEST_BASENAME)

DIR := $(addprefix $(DEPDIR), $(sort $(filter-out ./, $(dir $(BASENAME)))))    \
       $(addprefix $(OBJDIR), $(sort $(filter-out ./, $(dir $(BASENAME)))))

override SRCS := $(addprefix $(SRCDIR), $(addsuffix .c, $(BASENAME)))

override OBJS := $(addprefix $(OBJDIR), $(addsuffix .o, $(BASENAME)))

override DEPS := $(addprefix $(DEPDIR), $(addsuffix .d, $(BASENAME)))

override LIBFT := libft/libft.a

override MLX := minilibx-linux/libmlx.a

override LDFLAGS := -lmlx -lXext -lX11 -lft -lcmocka -lm

override LDLIBS := -L libft/ -L minilibx-linux/

override FILTERED_SRCS := $(strip $(foreach f,$(SRCS),$(if $(or $(findstring test,$(f)),$(findstring tmp,$(f))),,$(f))))

CC := cc

CFLAGS := -Wall -Wextra -Werror -Wunreachable-code
#-Wstrict-prototypes

ifeq (debug, $(MODE))
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Wstrict-prototypes -Wunreachable-code -Wstrict-prototypes -g3
endif

ifeq (opti, $(MODE))
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Wstrict-prototypes -Wunreachable-code -Wstrict-prototypes -Ofast -march=native -flto -ffast-math -funroll-loops -finline-functions -fomit-frame-pointer -fno-math-errno -funsafe-math-optimizations -DNDEBUG -pipe
endif

ifeq (gprof, $(MODE))
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Wstrict-prototypes -Wunreachable-code -Wstrict-prototypes -pg
endif

ifeq (asan, $(MODE))
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Wstrict-prototypes -Wunreachable-code -Wstrict-prototypes -fsanitize=address
endif

ifeq (msan, $(MODE))
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Wstrict-prototypes -Wunreachable-code -Wstrict-prototypes -fsanitize=memory
endif

ifeq (lsan, $(MODE))
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Wstrict-prototypes -Wunreachable-code -Wstrict-prototypes -fsanitize=leak
endif

CPPFLAGS := -Iincludes -Ilibft/includes -Iminilibx-linux/

DEPSFLAGS := -MD -MP -MF

MAKEFLAGS += --no-print-directory

.DEFAULT_GOAL = all

-include $(DEPS)

CURRENT_FLAGS := $(MODE)$(CC)$(CFLAGS)$(CPPFLAGS)$(LDFLAGS)$(LDLIBS)$(TEST)

ifneq ($(MODE),)
ifneq ($(shell cat $(FLAGFILE) 2>/dev/null), $(CURRENT_FLAGS))
$(shell mkdir -p $(BUILDDIR) && echo '$(CURRENT_FLAGS)' > $(FLAGFILE))
endif
endif

.PHONY: json
json:
	@/home/kporceil/.local/bin/compiledb $(MAKE) MODE="$(MODE)"

.PHONY: all
all:
	@$(MAKE) MODE="default" TEST="$(TEST)" $(NAME)

.PHONY: debug
debug:
	@$(MAKE) MODE="debug" TEST="$(TEST)" $(NAME)

.PHONY: asan
asan:
	@$(MAKE) MODE="asan" TEST="$(TEST)" $(NAME)

.PHONY: lsan
lsan:
	@$(MAKE) MODE="lsan" TEST="$(TEST)" $(NAME)

.PHONY: msan
msan:
	@$(MAKE) MODE="msan" TEST="$(TEST)" $(NAME)

.PHONY: gprof
gprof:
	@$(MAKE) MODE="gprof" TEST="$(TEST)" $(NAME)

.PHONY: opti
opti:
	@$(MAKE) MODE="opti" TEST="$(TEST)" $(NAME)

.PHONY: test
test:
	@$(MAKE) MODE="default" TEST="yes" $(NAME) && ./miniRT

$(NAME): $(OBJS) $(LIBFT) $(MLX) $(FLAGFILE)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(LDLIBS) $(LDFLAGS) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c | $(DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPSFLAGS) $(DEPDIR)$*.d -c $< -o $@

$(LIBFT): force
	@$(MAKE) MODE="$(MODE)" -C libft/

$(MLX): force
	@$(MAKE) -C minilibx-linux/

$(FLAGFILE): | $(BUILDDIR)
	@echo '$(CURRENT_FLAGS)' > $@

.PHONY: force
force:

$(DIR):
	mkdir -p $@

.PHONY: clean
clean:
	@$(MAKE) MODE="$(MODE)" clean -C libft/
	@$(MAKE) clean -C minilibx-linux/
	rm -rf $(BUILDDIR)

.PHONY: fclean
fclean: clean
	@$(MAKE) MODE="$(MODE)" fclean -C libft/
	rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: norm
norm:
	@norminette $(FILTERED_SRCS)
