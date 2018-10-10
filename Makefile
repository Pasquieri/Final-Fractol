# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/18 15:03:03 by cpalmier          #+#    #+#              #
#    Updated: 2018/08/07 15:58:06 by cpalmier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = src/main.c src/image.c src/init_env.c src/key_hooks.c src/consigne.c \
	  src/verif.c src/color.c src/burning_ship.c src/julia.c \
	  src/mandelbrot.c src/key_move.c src/put_pxl_img.c

HEADER = include/fractol.h libft/libft.h

OBJ = $(SRC:.c=.o)

COLOR = \033[1;33m
COLOR_OFF = \033[0m

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	make -C Minilibx
	@gcc -Wall -Werror -Wextra -I Minilibx/ Minilibx/libmlx.a \
		-framework OpenGL -framework AppKit \
		$(HEADER) $(SRC) libft/libft.a
	@mv a.out $(NAME)
	@echo "${COLOR}all : fractol created √${COLOR_OFF}"

./%.o : src/%.c
	@gcc -Wall -Werror -Wextra -I Minilibx/ Minilibx/libmlx.a \
		-framework OpenGL -framework AppKit \
		-c $< -o $@ -I $(HEADER) Libft/libft.a

clean :
	make -C libft clean
	make -C Minilibx clean
	@rm -rf $(OBJ)
	@echo "${COLOR}Fractol clean √${COLOR_OFF}"

fclean : clean
	make -C libft fclean
	@rm -rf $(NAME)
	@echo "${COLOR}Fractol fclean √${COLOR_OFF}"

re : fclean all
