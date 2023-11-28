# -----------\ Name \--------------------------------------------------------- #

NAME	:= cub3D
WIDTH := $(shell xdpyinfo | awk -F'[ x]+' '/dimensions:/ {print $$3}')
HEIGHT := $(shell xdpyinfo | awk -F'[ x]+' '/dimensions:/ {print $$4}')
WAV_FILE := $(PWD)/music.wav
MAP_NAME := map/map_ice_maze.cub

# -----------\ Directories \-------------------------------------------------- #

LIBFT_DIR	:= ./lib/libft/
LIBMLX		:= ./lib/MLX42
INC_DIREC := includes/
SRC_DIREC := sources/
OBJ_DIREC := build/

# -----------\ Compilation \-------------------------------------------------- #

CFLAGS	:= -Wextra -Wall -Werror -g -DWIDTH=$(WIDTH) -DHEIGHT=$(HEIGHT)
MD		:= -mkdir -p
WIDTHU = xdpyinfo | awk -F'[ x]+' '/dimensions:/ {print $4}';
HEIGHTU = xdpyinfo | awk -F'[ x]+' '/dimensions:/ {print $3}';

# -----------\ Files & sources \---------------------------------------------- #

HEADERS	:= -I $(INC_DIREC) -I $(LIBMLX)/include/MLX42 -I $(LIBFT_DIR)includes/
LIBS	:= $(LIBMLX)/build/libmlx42.a  -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/" \
		$(LIBFT_DIR)libft.a
SRCS	:= $(shell find $(SRC_DIREC) -iname "*.c")
OBJS := $(addprefix $(OBJ_DIREC), $(notdir $(SRCS:.c=.o)))

# -----------\ Rules \-------------------------------------------------------- #

.DEFAULT_GOAL := all
.DELETE_ON_ERROR:

all: lib $(NAME)

lib:
	@$(MAKE) -C $(LIBFT_DIR)
	@if [ ! -d "$(LIBMLX)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX); \
	fi
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJ_DIREC) $(OBJS)
	@$(CC) $(OBJS) -lm $(CFLAGS) $(LIBS) $(HEADERS) -o $(NAME) -lasound
	@echo "Cub3D compilation: 100%"

$(OBJ_DIREC)%.o: $(SRC_DIREC)%.c
	@$(CC) -o $@ $(CFLAGS) -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(OBJ_DIREC):
	@$(MD) $(OBJ_DIREC)
	@echo "Creating folder $(OBJ_DIREC)"

clean:
	@rm -fr $(OBJ_DIREC)
	@$(MAKE) clean -C $(LIBFT_DIR)

run: $(NAME)
	./$(NAME) $(MAP_NAME) & aplay $(WAV_FILE); kill $!

fclean: clean	
	@rm -fr $(LIBMLX)
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: clean all

log:
	git log -n 10 --pretty=format:"Author: %an - Date: %ad%nCommit ID: %H%nComment: %s%n%n" --date=format:"%d/%m/%Y à %H:%M"

.PHONY: all, clean, fclean, re, lib