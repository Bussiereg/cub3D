# -----------\ Name \--------------------------------------------------------- #

NAME = libft.a

# -----------\ Directories \-------------------------------------------------- #

INC_DIREC := includes/
SRC_DIREC := sources/
OBJ_DIREC := build/

# -----------\ Compilation \-------------------------------------------------- #

CFLAGS	:= -Wextra -Wall -Werror
AR		:= ar -rcs
MD		:= -mkdir -p

# -----------\ Files & sources \---------------------------------------------- #

HEADERS	:= -I ./includes
SRCS := ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	get_next_line.c \
	get_next_line_utils.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c 
OBJS := $(addprefix $(OBJ_DIREC), $(notdir $(SRCS:.c=.o)))

# -----------\ Rules \-------------------------------------------------------- #

all: $(NAME)

$(NAME): $(OBJ_DIREC) $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "libft compilation: 100%"
	
$(OBJ_DIREC)%.o: $(SRC_DIREC)%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(OBJ_DIREC):
	@$(MD) $(OBJ_DIREC)
	@echo "- Created folder $(OBJ_DIREC)"

clean:
	@rm -fr $(OBJ_DIREC)

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re
