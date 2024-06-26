# -----------\ Name \--------------------------------------------------------- #

NAME	:= cub3D
NAME_BONUS	:= cub3D_bonus
WIDTH := $(shell xdpyinfo | awk -F'[ x]+' '/dimensions:/ {print $$3}')
HEIGHT := $(shell xdpyinfo | awk -F'[ x]+' '/dimensions:/ {print $$4}')
WAV_FILE := $(PWD)/music.wav
MAP_NAME := map/map_level1.cub

# -----------\ Directories \-------------------------------------------------- #

LIBFT_DIR	:= ./lib/libft/
LIBMLX		:= ./lib/MLX42
INC_DIREC := includes/
INC_DIREC_BONUS := includes_bonus/
SRC_DIREC := sources/
SRC_DIREC_BONUS := sources_bonus/
OBJ_DIREC := build/
OBJ_DIREC_BONUS := build_bonus/

# -----------\ Compilation \-------------------------------------------------- #

CFLAGS	:= -Wextra -Wall -Werror -g -DWIDTH=$(WIDTH) -DHEIGHT=$(HEIGHT)
MD		:= -mkdir -p
WIDTHU = xdpyinfo | awk -F'[ x]+' '/dimensions:/ {print $4}';
HEIGHTU = xdpyinfo | awk -F'[ x]+' '/dimensions:/ {print $3}';

# -----------\ Files & sources \---------------------------------------------- #

HEADERS	:= -I $(INC_DIREC) -I $(LIBMLX)/include/MLX42 -I $(LIBFT_DIR)includes/
HEADERS_BONUS	:= -I $(INC_DIREC_BONUS) -I $(LIBMLX)/include/MLX42 -I $(LIBFT_DIR)includes/
LIBS	:= $(LIBMLX)/build/libmlx42.a  -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/" \
		$(LIBFT_DIR)libft.a
SRCS	:= 	$(SRC_DIREC)close.c \
			$(SRC_DIREC)color.c \
			$(SRC_DIREC)draw_background.c \
			$(SRC_DIREC)draw_viewport.c \
			$(SRC_DIREC)keyhook_main.c \
			$(SRC_DIREC)keyhook_moving.c \
			$(SRC_DIREC)keyhook_rotate.c \
			$(SRC_DIREC)main.c \
			$(SRC_DIREC)parse_info.c \
			$(SRC_DIREC)parse_main.c \
			$(SRC_DIREC)parse_texture.c \
			$(SRC_DIREC)parse_utils.c \
			$(SRC_DIREC)raycaster_calculus.c \
			$(SRC_DIREC)raycaster_main.c \
			$(SRC_DIREC)render.c
SRCS_BONUS	:= 	$(SRC_DIREC_BONUS)close_bonus.c \
			$(SRC_DIREC_BONUS)color_bonus.c \
			$(SRC_DIREC_BONUS)draw_background_bonus.c \
			$(SRC_DIREC_BONUS)draw_character_bonus.c \
			$(SRC_DIREC_BONUS)draw_minimap_bonus.c \
			$(SRC_DIREC_BONUS)draw_sprite_bonus.c \
			$(SRC_DIREC_BONUS)draw_sprite_sort_bonus.c \
			$(SRC_DIREC_BONUS)draw_viewport_bonus.c \
			$(SRC_DIREC_BONUS)keyhook_main_bonus.c \
			$(SRC_DIREC_BONUS)keyhook_moving_bonus.c \
			$(SRC_DIREC_BONUS)keyhook_rotate_bonus.c \
			$(SRC_DIREC_BONUS)main_bonus.c \
			$(SRC_DIREC_BONUS)mousehook_bonus.c \
			$(SRC_DIREC_BONUS)music_bonus.c \
			$(SRC_DIREC_BONUS)parse_info_bonus.c \
			$(SRC_DIREC_BONUS)parse_main_bonus.c \
			$(SRC_DIREC_BONUS)parse_texture_bonus.c \
			$(SRC_DIREC_BONUS)parse_texture_sprite_bonus.c \
			$(SRC_DIREC_BONUS)parse_utils_bonus.c \
			$(SRC_DIREC_BONUS)raycaster_calculus_bonus.c \
			$(SRC_DIREC_BONUS)raycaster_main_bonus.c \
			$(SRC_DIREC_BONUS)render_bonus.c
OBJS := $(addprefix $(OBJ_DIREC), $(notdir $(SRCS:.c=.o)))
OBJS_BONUS := $(addprefix $(OBJ_DIREC_BONUS), $(notdir $(SRCS_BONUS:.c=.o)))

# -----------\ Rules \-------------------------------------------------------- #

.DEFAULT_GOAL := all
.DELETE_ON_ERROR:

all: lib $(NAME)

bonus: lib $(NAME_BONUS)

lib:
	@$(MAKE) -C $(LIBFT_DIR)
	@if [ ! -d "$(LIBMLX)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX); \
	fi
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJ_DIREC) $(OBJS)
	@$(CC) $(OBJS) -lm $(CFLAGS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "Cub3D compilation: 100%"

$(OBJ_DIREC)%.o: $(SRC_DIREC)%.c
	@$(CC) -o $@ $(CFLAGS) -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(OBJ_DIREC):
	@$(MD) $(OBJ_DIREC)
	@echo "Creating folder $(OBJ_DIREC)"

$(NAME_BONUS): $(OBJ_DIREC_BONUS) $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) -lm $(CFLAGS) -lpulse -lpulse-simple $(LIBS) $(HEADERS_BONUS) -o $(NAME_BONUS)
	@echo "Cub3D bonus compilation: 100%"

$(OBJ_DIREC_BONUS)%.o: $(SRC_DIREC_BONUS)%.c
	@$(CC) -o $@ $(CFLAGS) -c $< $(HEADERS_BONUS) && printf "Compiling: $(notdir $<)\n"

$(OBJ_DIREC_BONUS):
	@$(MD) $(OBJ_DIREC_BONUS)
	@echo "Creating folder $(OBJ_DIREC_BONUS)"

clean:
	@rm -fr $(OBJ_DIREC)
	@rm -fr $(OBJ_DIREC_BONUS)
	@$(MAKE) clean -C $(LIBFT_DIR)

run: bonus $(NAME_BONUS)
	./$(NAME_BONUS) $(MAP_NAME) & aplay $(WAV_FILE); kill $!

fclean: clean	
	@rm -fr $(LIBMLX)
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: clean all

re_bonus: clean bonus

log:
	git log -n 10 --pretty=format:"Author: %an - Date: %ad%nCommit ID: %H%nComment: %s%n%n" --date=format:"%d/%m/%Y à %H:%M"

.PHONY: all, clean, fclean, re, lib
