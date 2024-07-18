# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 19:36:19 by ysanchez          #+#    #+#              #
#    Updated: 2024/07/18 20:53:17 by gpinilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Suprimir la salida de los comandos make
MAKEFLAGS += --silent

################################################################################
### COLORS
################################################################################

DEL_LINE =		\033[2K
NC		=		\033[0m
ITALIC =		\033[3m
BOLD =			\033[1m
DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

################################################################################
### COMMANDS
################################################################################

NAME            = cub3D
NAME_BONUS      = cub3D_bonus
LIBFT           = Libft/libft.a
MINILIBX        = minilibx-linux/libmlx.a
CC              = gcc
FLAGS           = -g #-Wall -Werror -Wextra -fsanitize=leak
LIB_FLAGS       = -Lminilibx-linux -lmlx -Iminilibx-linux -lXext -lX11 -lm -lz
RM              = rm -rf

SRC             = src/main.c src/error.c src/parser.c src/utils.c src/data_init.c src/grafic_utils.c src/map_parser.c src/loop_game.c src/cast_rays.c src/draw.c src/handle_keys.c src/initialize_game.c src/key_helper.c src/mouse.c
SRC_BONUS       = src_b/main_bonus.c src_b/error_bonus.c src_b/parser_bonus.c src_b/utils_bonus.c src/map_parser.c

DIR_OBJ         = temp/
DIR_OBJ_BONUS   = temp/bonus/
OBJ             = $(SRC:src/%.c=$(DIR_OBJ)%.o)
OBJ_BONUS       = $(SRC_BONUS:src_b/%.c=$(DIR_OBJ_BONUS)%.o)

HEADER          = ./include/cub3d.h
HEADER_BONUS    = ./include/cub3d_bonus.h

################################################################################
### RULES
################################################################################

all: $(DIR_OBJ) libft_make libmlx_make $(NAME)
	@echo "$(GREEN)$(NAME) is up to date ✓$(DEF_COLOR)\n"

bonus: $(OBJ) $(HEADER) $(LIBFT) $(MINILIBX) Makefile
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(LIB_FLAGS) -o $(NAME)
	@echo "$(GREEN)Created $(NAME) ✓$(DEF_COLOR)\n"

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

$(DIR_OBJ)%.o: src/%.c $(HEADER) Makefile $(LIBFT) | $(DIR_OBJ)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "${BLUE} ◎ $(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"

libft_make: $(LIBFT)

$(LIBFT):
	@$(MAKE) -C Libft
	@echo "$(GREEN)\nCreated $(LIBFT) ✓$(DEF_COLOR)\n"

libmlx_make: $(MINILIBX)

$(MINILIBX):
	@$(MAKE) -C minilibx-linux
	@echo "$(GREEN)\nCreated $(MINILIBX) ✓$(DEF_COLOR)\n"

$(NAME): $(OBJ) $(HEADER) $(LIBFT) $(MINILIBX) Makefile
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(LIB_FLAGS) -o $(NAME)
	@echo "$(GREEN)Created $(NAME) ✓$(DEF_COLOR)\n"

clean:
	@$(RM) $(DIR_OBJ) $(DIR_OBJ_BONUS)
	@$(MAKE) -C minilibx-linux clean
	@$(MAKE) -C Libft clean
	@echo "${RED}Objects and dependencies successfully removed${DEF_COLOR}"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@$(MAKE) -C Libft fclean
	@echo "${RED}Executables successfully removed${DEF_COLOR}"

re: fclean all

.PHONY: all clean fclean re bonus libft_make libmlx_make
