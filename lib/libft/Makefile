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
SRCS	:= $(shell find $(SRC_DIREC) -iname "*.c")
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
