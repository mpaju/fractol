# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/17 17:18:15 by mpaju             #+#    #+#              #
#    Updated: 2017/10/21 16:11:49 by mpaju            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol
UNAME		=	Fractol

CC			=	gcc
FLAGS		=	# -Wall -Wextra -Werror

SRC_DIR		=	sources
FILES		=	main.c 
SRCS		=	$(addprefix $(SRC_DIR)/, $(FILES))

HEAD_DIR	=	includes
HEAD		=	fractol.h
HEAD_FILES	=	$(addprefix $(HEAD_DIR)/, $(HEAD))
LIBFT_HEAD	=	-Ilibft/includes/
HEAD_LINK	=	-I
HEAD_LOC	=	$(addprefix $(HEAD_LINK), $(HEAD_DIR))

OBJ_DIR		=	objects
OBJ_FILES	=	$(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
OBJ_DIRS	=	$(sort $(dir $(OBJ_FILES)))

LIB			=	libft/libft.a minilibx/libmlx.a
LIBS		=	libft libmlx
LIBFT_DIR	=	libft/ 
LIBX_DIR	=	minilibx/
MYLIB		=	-L./libft -lft -L./minilibx -lmlx
EXT_LIB		=	-framework OpenGL -framework AppKit

all: build $(NAME) 

$(NAME): $(LIB) $(OBJ_FILES)
	$(CC) -o $@ $^ -g $(MYLIB) $(EXT_LIB)
	@echo "\033[0;37m$(UNAME) make all done\033[0;38m"

build:
	@mkdir -p $(OBJ_DIRS)

$(LIB):
	@make -C $(LIBFT_DIR)
	@make -C $(LIBX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(FLAGS) -I./minilibx_macos/ $(HEAD_LOC) $(LIBFT_HEAD) -c -o $@ $< -g

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(LIBX_DIR)
	@rm -f $(OBJ_FILES)
	@echo "\033[0;33m$(UNAME) make clean done\033[0;38m"

fclean:
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(LIBX_DIR)
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@echo "\033[0;34m$(UNAME) make fclean done\033[0;38m"

re: fclean all
	@echo "\033[0;36m$(UNAME) make re done\033[0;38m"

.PHONY: re fclean clean deb all
