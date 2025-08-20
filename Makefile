NAME := minishell

BONUSNAME := minishell_bonus

override SRCDIR := srcs/

override BONUSSRCDIR := $(addprefix bonus/, $(SRCDIR))

override BUILDDIR := .build/

override BONUSBUILDDIR := $(addprefix bonus/, $(BUILDDIR))

override OBJDIR := $(addprefix $(BUILDDIR), objs/)

override BONUSOBJDIR := $(addprefix bonus/, $(OBJDIR))

override DEPDIR := $(addprefix $(BUILDDIR), deps/)

override BONUSDEPDIR := $(addprefix bonus/, $(DEPDIR))

BASENAME := 

DIR := $(addprefix $(DEPDIR), $(sort $(filter-out ./, $(dir $(BASENAME)))))    \
       $(addprefix $(OBJDIR), $(sort $(filter-out ./, $(dir $(BASENAME)))))

override SRCS := $(addprefix $(SRCDIR), $(addsuffix .c, $(BASENAME)))

override OBJS := $(addprefix $(OBJDIR), $(addsuffix .o, $(BASENAME)))

override DEPS := $(addprefix $(DEPDIR), $(addsuffix .d, $(BASENAME)))

override LIBFT := libft/libft.a

override FILTERED_SRCS := $(filter-out $(SRCDIR)tmp_%.c, $(filter-out $(SRCDIR)TEST/%, $(filter-out $(SRCDIR)PRINT/%, $(SRCS)))) $(filter-out includes/tmp_%.h, $(addprefix includes/, $(shell ls includes/))) $(addprefix $(dir $(LIBFT))srcs/, $(shell ls $(dir $(LIBFT))srcs/)) $(addprefix $(dir $(LIBFT))includes/, $(shell ls $(dir $(LIBFT))includes/))

override LDFLAGS := -lft -lcmocka

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
