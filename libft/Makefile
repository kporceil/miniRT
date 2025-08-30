NAME := libft.a

MODE := default

override BUILDDIR := .build/$(MODE)/

override FLAGFILE := .build/.compile_flags

override OBJDIR := $(addprefix $(BUILDDIR), objs/)

override DEPDIR := $(addprefix $(BUILDDIR), deps/)

override SRCDIR := srcs/

BASENAME := ft_isalpha \
		   ft_isascii \
		   ft_isdigit \
		   ft_isspace \
		   ft_isprint \
		   ft_toupper \
		   ft_tolower \
		   ft_isalnum \
		   ft_bzero \
		   ft_memset \
		   ft_memcpy \
		   ft_memmove \
		   ft_memcmp \
		   ft_memchr \
		   ft_strlen \
		   ft_strchr \
		   ft_strchrs \
		   ft_strrchr \
		   ft_strncmp \
		   ft_strnstr \
		   ft_strlcpy \
		   ft_strlcat \
		   ft_calloc \
		   ft_strdup \
		   ft_strndup \
		   ft_atoi \
		   ft_substr \
		   ft_putchar_fd \
		   ft_putstr_fd \
		   ft_putendl_fd \
		   ft_putnbr_fd \
		   ft_strmapi \
		   ft_striteri \
		   ft_itoa \
		   ft_strjoin \
		   ft_strjoinarr \
		   ft_strtrim \
		   ft_split \
		   ft_splits \
		   ft_lstnew \
		   ft_lstadd_front \
		   ft_lstsize \
		   ft_lstlast \
		   ft_lstadd_back \
		   ft_lstdelone \
		   ft_lstclear \
		   ft_lstiter \
		   ft_lstmap \
		   ft_sqrt \
		   ft_btriter \
		   ft_btrleft \
		   ft_btrright \
		   ft_lstnext \
		   ft_strjoinarr \
		   ft_tablen

override SRCS := $(addprefix $(SRCDIR), $(addsuffix .c, $(BASENAME)))

override OBJS := $(addprefix $(OBJDIR), $(addsuffix .o, $(BASENAME)))

override DEPS := $(addprefix $(DEPDIR), $(addsuffix .d, $(BASENAME)))

CC := cc

CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Wstrict-prototypes -fPIE

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

ifeq (asan, $(MODE))
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Wstrict-prototypes -Wunreachable-code -Wstrict-prototypes -fPIE -fsanitize=leak
endif

override CPPFLAGS := -I

override INCS := ./includes

override DEPSFLAGS := -MD -MP -MF

override AR := ar

override ARFLAGS := rcs

override RM := rm -rf

override MAKEFLAGS += --no-print-directory

CURRENT_FLAGS := $(MODE)$(CC)$(CFLAGS)$(CPPFLAGS)$(LDFLAGS)$(LDLIBS)

ifneq ($(shell cat $(FLAGFILE) 2>/dev/null), $(CURRENT_FLAGS))
$(shell mkdir -p $(BUILDDIR) && echo '$(CURRENT_FLAGS)' > $(FLAGFILE))
endif

all:
	@$(MAKE) MODE="$(MODE)" $(NAME)

$(NAME): $(OBJS) $(FLAGFILE)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo ""
	@echo "libft.a created."

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR) $(DEPDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCS) $(DEPSFLAGS) $(DEPDIR)$*.d -c $< -o $@ $(COMPFLAGS)

$(OBJDIR) $(DEPDIR):
	mkdir -p $@

$(FLAGFILE): | $(BUILDDIR)
	@echo '$(CURRENT_FLAGS)' > $@

clean:
	$(RM) $(BUILDDIR)

fclean: clean
	$(RM) $(NAME) $(SONAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
