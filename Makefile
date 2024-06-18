# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 19:36:19 by ysanchez          #+#    #+#              #
#    Updated: 2024/06/18 21:17:26 by ysanchez         ###   ########.fr        #
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

NAME			= cub3D
NAME_BONUS		= cub3D_bonus
LIBFT			= Libft/libft.a
CC				= cc
FLAGS			= -Wall -Werror -Wextra -fsanitize=address
RM				= rm -f

SRC				= src/main.c src/error.c src/parser.c src/utils.c
SRC_BONUS		= src_b/main_bonus.c src_b/error_bonus.c src_b/parser_bonus.c src_b/utils_bonus.c

OBJ				= $(SRC:.c=.o)
OBJ_BONUS		= $(SRC_BONUS:.c=.o)

HEADER			= ./include/cub3d.h
HEADER_BONUS	= ./include/cub3d_bonus.h

DEPS			= $(OBJ:.o=.d)
BONUS_DEPS		= $(OBJ_BONUS:.o=.d)

################################################################################
### RULES
################################################################################

all: $(NAME)
	@echo "$(GREEN)$(NAME) is up to date ✓$(DEF_COLOR)\n"

bonus: $(NAME_BONUS)
	@echo "$(GREEN)$(NAME_BONUS) is up to date ✓$(DEF_COLOR)\n"

$(NAME): libft $(OBJ) $(HEADER)
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Created $(NAME) ✓$(DEF_COLOR)\n"

$(NAME_BONUS): libft $(OBJ_BONUS) $(HEADER_BONUS)
	@$(CC) $(FLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)
	@echo "$(GREEN)Created $(NAME_BONUS) ✓$(DEF_COLOR)\n"

%.o: %.c $(HEADER) Makefile
	@$(CC) $(FLAGS) -MMD -c $< -o $@
	@echo "${BLUE} ◎ $(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"

%.o: $(SRC_BONUS)%.c $(HEADER_BONUS) Makefile
	@$(CC) $(FLAGS) -MMD -c $< -o $@
	@echo "${BLUE} ◎ $(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"

-include $(DEPS)
-include $(BONUS_DEPS)

libft:
	@$(MAKE) -C Libft
	@echo "$(GREEN)\nCreated $(LIBFT) ✓$(DEF_COLOR)\n"

clean:
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@$(RM) $(DEPS) $(BONUS_DEPS)
	@$(MAKE) -C Libft clean
	@echo "${RED}Objects and dependencies successfully removed${NC}"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@$(MAKE) -C Libft fclean
	@echo "${RED}Executables successfully removed${NC}"

re: fclean all

.PHONY: all clean fclean re bonus libft