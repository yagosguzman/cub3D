# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 19:36:19 by ysanchez          #+#    #+#              #
#    Updated: 2024/06/18 20:20:38 by ysanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAME_BONUS = cub3D_bonus
CC = cc
FLAGS = -Wall -Werror -Wextra -fsanitize=address
RM = rm -f
HEADER = ./include/cub3d.h
HEADER_BONUS = ./include/cub3d_bonus.h
SRC = src/
SRC_BONUS = src_b/
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
DEPS = $(addsuffix .d, $(basename $(SRC)))
BONUSDEPS = $(addsuffix .d, $(basename $(SRC_BONUS)))\

all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJ) $(HEADER)
		@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@echo "Executable ready!"

%.o:%.c Makefile 
	@$(CC) $(FLAGS) -c $< -o $@


libft_make:
	@$(MAKE) -C Libft
	@echo "$(GREEN)\nCreated $(LIBFT) ✓$(DEF_COLOR)\n"

bonus: $(NAME_BONUS)

-include $(BONUS_DEPS)
$(NAME_BONUS): $(OBJ_BONUS) $(HEADER_BONUS)
	@$(CC) $(FLAGS) $(SRC_BONUS) -Lmlx_linux -lmlx_Linux -L./mlx_linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME_BONUS)
	@echo "BONUS: Executable ready!"
	
%bonus.o:%bonus.c Makefile 
	@$(CC) $(FLAGS) -Imlx_linux -03 -c $< -o $@

clean:
	@make -C ./mlx_linux clean
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@$(RM) $(DEPS) $(BONUS_DEPS)
	@echo "Objects and libraries successfully removed"

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "Executable successfully removed"

re: fclean all

.PHONY: make all clean fclean re bonus