# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: vbusekru <vbusekru@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/01/02 10:16:29 by vbusekru      #+#    #+#                  #
#    Updated: 2024/01/02 10:16:29 by vbusekru      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = Libft/libft.a

LIBFTDIR = Libft

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar -rsc

SOURCE =	ft_printf.c \
				ft_write_various.c \
				ft_write_hexa.c \
				ft_write_unsigned_int.c \
				main.c \

OBJECTS = $(SOURCE:%.c=%.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)
	
$(NAME): $(LIBFT) $(OBJECTS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJECTS) $(LIBFT)

%.o:%.c 
	$(CC) $(CFLAGS) -c -o $@ $^ -I $(LIBFTDIR)

clean: 
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(OBJECTS)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) $(NAME)

compile: all
	$(CC) $(CFLAGS) main.c $(NAME)

re: fclean all

.PHONY: all clean fclean re
