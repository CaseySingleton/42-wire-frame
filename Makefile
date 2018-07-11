# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csinglet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 18:59:57 by csinglet          #+#    #+#              #
#    Updated: 2018/07/08 16:54:27 by csinglet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf
FLAGS			= -Wall -Werror -Wextra
FRAMEWORKS		= -framework OpenGL -framework AppKit -L . -lmlx
FILES			= main.c map.c image.c list_functions.c key_commands.c
SRC				= $(addprefix srcs/, $(FILES))
OBJ				= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME):
	@make -C libft/ re
	@make -C libmlx/ re
	@cp libft/libft.a ./
	@cp libmlx/my_libmlx.a ./
	@gcc $(FLAGS) -c $(SRC) -I /includes -I /libft -I .minilibx -I ./libmlx
	@gcc $(FLAGS) $(OBJ) -o $(NAME) libft.a my_libmlx.a -I ./minilibx $(FRAMEWORKS)
	@make clean

test:
	@gcc $(FLAGS) -c $(SRC) -I /libft -I /minilibx -I /includes/libmlx
	@gcc $(FLAGS) $(OBJ) -o $(NAME) libft.a my_libmlx.a -I ./minilibx $(FRAMEWORKS)
	@make clean

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
