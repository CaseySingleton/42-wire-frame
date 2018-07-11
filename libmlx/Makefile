# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csinglet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 18:59:57 by csinglet          #+#    #+#              #
#    Updated: 2018/06/20 19:58:28 by csinglet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= my_libmlx.a
FLAGS			= -Wall -Werror -Wextra
FRAMEWORKS		= -framework OpenGL -framework AppKit -L . -lmlx
FILES			= draw.c matrix_rotation.c matrix_management.c
SRCS			= $(addprefix srcs/, $(FILES))
OBJ				= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME):
	@make -C libft/ all
	@make -C minilibx/ all
	@cp minilibx/libmlx.a ./
	@cp libft/libft.a ./
	@gcc $(FLAGS) -c $(SRCS) -I ./libft -I ./minilibx
	@ar rcs $(NAME) $(OBJ) libft.a libmlx.a
	@make clean

test:
	@gcc $(FLAGS) -c $(SRCS) main_basic.c  -I ./libft -I ./minilibx
	@gcc $(FLAGS) $(OBJ) main_basic.o -o $(NAME) libft.a -I ./minilibx $(FRAMEWORKS) -L . -lmlx

clean:
	@/bin/rm -f $(OBJ)
	@make -C libft/ clean
	@make -C minilibx/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft.a
	@make -C libft/ fclean
	@make -C minilibx/ clean

re: fclean all
