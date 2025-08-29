NAME := miniRT

BONUSNAME := minishell_bonus

override SRCDIR := srcs/

override BONUSSRCDIR := $(addprefix bonus/, $(SRCDIR))

override BUILDDIR := .build/

override BONUSBUILDDIR := $(addprefix bonus/, $(BUILDDIR))

override OBJDIR := $(addprefix $(BUILDDIR), objs/)

override BONUSOBJDIR := $(addprefix bonus/, $(OBJDIR))

override DEPDIR := $(addprefix $(BUILDDIR), deps/)

override BONUSDEPDIR := $(addprefix bonus/, $(DEPDIR))

BASENAME := experiments/main \
			$(addprefix tuples/, point vector add substract negate scalar magnitude normalize dot_product cross_product) \
			$(addprefix color/, color add substract scalar mult) \
			$(addprefix canvas/, canva write_pixel tmp_canva_to_ppm) \
			$(addprefix matrix/, create comparison mult identity transposing determinant submatrix minors cofactor is_invertible invert translation scaling rotation shearing) \
			$(addprefix ray/, create position intersect hit transform) \
			$(addprefix spheres/, create) \
			$(addprefix light/, normal reflect point_light material phong) \
			$(addprefix test/, my_assert \
				$(addprefix tuples/, create_tests add_tests substract_tests negate_tests scalar_tests magnitude_tests normalizing_tests dot_product_tests cross_product_tests) \
				$(addprefix color/, create_tests add_tests substract_tests scalar_tests mult_tests) \
				$(addprefix canvas/, create_tests write_pixel_tests ppm_tests) \
				$(addprefix matrix/, create_tests comparison_tests mult_tests transposing_tests determinant_tests submatrix_tests minors_tests cofactor_tests larger_determinant_tests inverting_tests translation_tests scaling_tests rotation_tests shearing_tests chaining_tests) \
				$(addprefix ray/, create_tests position_tests sphere_intersect_tests hit_tests transform_tests) \
				$(addprefix light/, normal_tests reflection_tests point_light_tests material_tests phong_tests))

DIR := $(addprefix $(DEPDIR), $(sort $(filter-out ./, $(dir $(BASENAME)))))    \
       $(addprefix $(OBJDIR), $(sort $(filter-out ./, $(dir $(BASENAME)))))

override SRCS := $(addprefix $(SRCDIR), $(addsuffix .c, $(BASENAME)))

override OBJS := $(addprefix $(OBJDIR), $(addsuffix .o, $(BASENAME)))

override DEPS := $(addprefix $(DEPDIR), $(addsuffix .d, $(BASENAME)))

override LIBFT := libft/libft.a

override FILTERED_SRCS := $(strip $(foreach f,$(SRCS),$(if $(or $(findstring test,$(f)),$(findstring tmp,$(f))),,$(f))))

override LDFLAGS := -lft -lcmocka -lm

override LDLIBS := -L libft/

CC := cc

CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Wstrict-prototypes -fPIE -Wunreachable-code -Wstrict-prototypes -fPIE

CPPFLAGS := -Iincludes -Ilibft/includes

DEPSFLAGS := -MD -MP -MF

COMPFLAGS :=

MAKEFLAGS += --no-print-directory

.DEFAULT_GOAL = all

-include $(DEPS)

.PHONY: json
json:
	@/home/kporceil/.local/bin/compiledb $(MAKE) COMPFLAGS="$(COMPFLAGS)"

.PHONY: debug
debug: fclean
	@$(MAKE) COMPFLAGS="-g3" $(NAME)

.PHONY: sanitize
sanitize: fclean
	@$(MAKE) COMPFLAGS="-fsanitize=address -g3" $(NAME)

.PHONY: all
all:
	@$(MAKE) COMPFLAGS="$(COMPFLAGS)" $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CLAGS) $(CPPFLAGS) $(OBJS) $(LDLIBS) $(LDFLAGS) -o $(NAME) $(COMPFLAGS)

$(OBJDIR)%.o: $(SRCDIR)%.c | $(DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPSFLAGS) $(DEPDIR)$*.d -c $< -o $@ $(COMPFLAGS)

$(LIBFT): force
	@$(MAKE) COMPFLAGS="$(COMPFLAGS)" -C libft/

.PHONY: force
force:

$(DIR):
	mkdir -p $@

.PHONY: clean
clean:
	@$(MAKE) clean -C libft/
	rm -rf $(BUILDDIR)

.PHONY: fclean
fclean: clean
	@$(MAKE) fclean -C libft/
	rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: norm
norm:
	@norminette $(FILTERED_SRCS)
