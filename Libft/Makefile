# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpinilla <gpinilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/29 13:04:21 by gpinilla          #+#    #+#              #
#    Updated: 2024/06/22 17:59:22 by gpinilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Suprimir la salida de los comandos make
MAKEFLAGS += --silent

#==================COLORS==================#

GREEN	=	\033[38;5;118m
RED		=	\033[0;91m
PURPLE	=	\033[38;5;171m
BLUE	=	\033[38;5;14m
NC		=	\033[0m
YELLOW	=	\033[38;5;228m

#=================COMMANDS=================#

LIB		=	ar rcs
CC		=	gcc
CCFLAGS	=	-Wall -Wextra -Werror
INCFLAG	=	-I./inc
RM		=	rm -fr

#==================FILES===================#

NAME			=	libft.a
INCLUDE 		=	./inc/libft.h
PRINTF			=	printf/
GETLINE			=	get_next_line/
SRC				=	ft_memset.c ft_bzero.c ft_strlen.c ft_atoi.c ft_isdigit.c ft_isalpha.c\
					ft_isprint.c ft_isascii.c ft_isalnum.c ft_memchr.c ft_memcpy.c\
					ft_memcmp.c ft_memmove.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c\
					ft_strncmp.c ft_toupper.c ft_tolower.c ft_strnstr.c ft_strrchr.c ft_calloc.c\
					ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_substr.c\
					ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_itoa.c ft_split.c ft_striteri.c\
					ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
					ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
					ft_lstclear.c ft_lstiter.c ft_lstmap.c\

FILESPRINTF		=	characters.c ft_printf.c numbers.c
SRCPRINTF		=	$(addprefix $(PRINTF),$(FILESPRINTF))

FILESGETLINE 	=	get_next_line.c
SRCGETLINE		=	$(addprefix $(GETLINE),$(FILESGETLINE)) 

DIR_OBJ 		=	temp/
OBJ 			=	$(addprefix $(DIR_OBJ),$(SRC:.c=.o))
OBJPRINT 		=	$(addprefix $(DIR_OBJ),$(SRCPRINTF:.c=.o))
OBJGETLINE 		=	$(addprefix $(DIR_OBJ),$(SRCGETLINE:.c=.o))

#==================RULES===================#

all: temp $(NAME)

temp:
	@mkdir -p $(DIR_OBJ)
	@mkdir -p $(DIR_OBJ)$(PRINTF)
	@mkdir -p $(DIR_OBJ)$(GETLINE)

$(NAME): $(OBJ) $(OBJPRINT) $(OBJGETLINE)
	@$(LIB) $@ $(OBJ) $(OBJPRINT) $(OBJGETLINE)
	@printf "\n\n${GREEN}Compiled $@ ✓✓${NC}\n\n"

$(DIR_OBJ)%.o: %.c $(INCLUDE) Makefile
	@mkdir -p $(DIR_OBJ)
	@$(CC) $(CCFLAGS) $(INCFLAG) -c $< -o $@
	@printf "\r                                                                           "
	@printf "${PURPLE}\r ⚙️ -I./ -c $< -o $@ ${NC}"

clean:
	@$(RM) $(DIR_OBJ)

fclean: clean
	@$(RM) $(NAME)
	@echo "${RED}DELETING LIBFT${NC}"

re: fclean all

.PHONY: all clean fclean re 