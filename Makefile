# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rfinneru <rfinneru@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/11/02 14:13:52 by rfinneru      #+#    #+#                  #
#    Updated: 2023/11/16 15:57:49 by rfinneru      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=cc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC= ft_printf.c ft_printf_utils.c ft_putnbr_base.c ft_putnbr.c arg_c.c arg_s.c arg_d_i.c arg_x_X.c arg_u.c arg_p.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(LIBFT): 
	make -C $(LIBFT_DIR) all

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

