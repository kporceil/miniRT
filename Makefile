NAME := miniRT

MODE := normal

override SRCDIR := srcs/

override BUILDDIR := .build/$(MODE)/

override FLAGFILE := .build/.compile_flags

override OBJDIR := $(addprefix $(BUILDDIR), objs/)

override DEPDIR := $(addprefix $(BUILDDIR), deps/)

ifeq (test, $(MODE))
MAIN := test_main
TEST_BASENAME :=  $(addprefix test/, my_assert \
					$(addprefix tuples/, create_tests add_tests substract_tests negate_tests scalar_tests magnitude_tests normalizing_tests dot_product_tests cross_product_tests) \
					$(addprefix color/, create_tests add_tests substract_tests scalar_tests mult_tests) \
					$(addprefix canvas/, create_tests write_pixel_tests ppm_tests) \
					$(addprefix matrix/, create_tests comparison_tests mult_tests transposing_tests determinant_tests submatrix_tests minors_tests cofactor_tests larger_determinant_tests inverting_tests translation_tests scaling_tests rotation_tests shearing_tests chaining_tests) \
					$(addprefix ray/, create_tests position_tests sphere_intersect_tests hit_tests transform_tests) \
					$(addprefix light/, normal_tests reflection_tests point_light_tests material_tests phong_tests))
endif
ifneq (test, $(MODE))
MAIN := main
TEST_BASENAME :=
endif

BASENAME := $(MAIN) \
			$(addprefix tuples/, point vector add substract negate scalar magnitude normalize dot_product cross_product) \
			$(addprefix color/, color add substract scalar mult) \
			$(addprefix canvas/, canva write_pixel tmp_canva_to_ppm) \
			$(addprefix matrix/, create comparison mult identity transposing determinant submatrix minors cofactor is_invertible invert translation scaling rotation shearing) \
			$(addprefix ray/, create position intersect hit transform) \
			$(addprefix spheres/, create set_matrix) \
			$(addprefix light/, normal reflect point_light material phong) \
			$(TEST_BASENAME)

DIR := $(addprefix $(DEPDIR), $(sort $(filter-out ./, $(dir $(BASENAME)))))    \
       $(addprefix $(OBJDIR), $(sort $(filter-out ./, $(dir $(BASENAME)))))

override SRCS := $(addprefix $(SRCDIR), $(addsuffix .c, $(BASENAME)))

override OBJS := $(addprefix $(OBJDIR), $(addsuffix .o, $(BASENAME)))

override DEPS := $(addprefix $(DEPDIR), $(addsuffix .d, $(BASENAME)))

override LIBFT := libft/libft.a

override LDFLAGS := -lft -lcmocka -lm

override LDLIBS := -L libft/

override FILTERED_SRCS := $(strip $(foreach f,$(SRCS),$(if $(or $(findstring test,$(f)),$(findstring tmp,$(f))),,$(f))))

CC := cc

CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Wstrict-prototypes -Wunreachable-code -Wstrict-prototypes -fPIE

ifeq (debug, $(MODE))
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Wstrict-prototypes -Wunreachable-code -Wstrict-prototypes -fPIE -g3
endif

ifeq (opti, $(MODE))
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Wstrict-prototypes -Wunreachable-code -Wstrict-prototypes -fPIE -Ofast
endif

ifeq (gprof, $(MODE))
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Wstrict-prototypes -Wunreachable-code -Wstrict-prototypes -fPIE -pg
endif

ifeq (asan, $(MODE))
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Wstrict-prototypes -Wunreachable-code -Wstrict-prototypes -fPIE -fsanitize=address
endif

CPPFLAGS := -Iincludes -Ilibft/includes

DEPSFLAGS := -MD -MP -MF

MAKEFLAGS += --no-print-directory

.DEFAULT_GOAL = all

-include $(DEPS)

CURRENT_FLAGS := $(MODE)$(CC)$(CFLAGS)$(CPPFLAGS)$(LDFLAGS)$(LDLIBS)

ifneq ($(shell cat $(FLAGFILE) 2>/dev/null), $(CURRENT_FLAGS))
$(shell mkdir -p $(BUILDDIR) && echo '$(CURRENT_FLAGS)' > $(FLAGFILE))
endif

.PHONY: json
json:
	@/home/kporceil/.local/bin/compiledb $(MAKE) MODE="$(MODE)"

.PHONY: all
all:
	@$(MAKE) MODE="$(MODE)" $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FLAGFILE)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(LDLIBS) $(LDFLAGS) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c | $(DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPSFLAGS) $(DEPDIR)$*.d -c $< -o $@

$(LIBFT): force
	@$(MAKE) MODE="$(MODE)" -C libft/

$(FLAGFILE): | $(BUILDDIR)
	@echo '$(CURRENT_FLAGS)' > $@

.PHONY: force
force:

$(DIR):
	mkdir -p $@

.PHONY: clean
clean:
	@$(MAKE) MODE="$(MODE)" clean -C libft/
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
