# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: vbusekru <vbusekru@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/12/06 12:23:58 by vbusekru      #+#    #+#                  #
#    Updated: 2023/12/29 15:45:06 by vbusekru      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES_MAND =	ft_printf.c \
				main.c \
				ft_write_various.c \
				ft_write_hexa.c \
				ft_write_unsigned_int.c \
				Libft/ft_itoa.c \
				Libft/ft_putstr_fd.c \
				Libft/ft_calloc.c \
				Libft/ft_memset.c \
				Libft/ft_bzero.c \
				Libft/ft_strlcpy.c \
				Libft/ft_strlen.c \
				Libft/ft_strjoin.c \

OBJS_MAND = $(SOURCES_MAND:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

ifdef DEBUG
CFLAGS += -g
endif

AR = ar

all: $(NAME)

$(NAME): $(OBJS_MAND)
	$(AR) rcs $(NAME) $(OBJS_MAND)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_MAND) $(OBJS_BONUS)

fclean:clean
	rm -f $(NAME)

compile: all
	$(CC) $(CFLAGS) main.c $(NAME)

debug:
	make DEBUG=1 compile

re: fclean all

.PHONY: all bonus clean fclean re