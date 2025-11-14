CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
HEADER = libftprintf.h
SRCS = ft_printf.c print_address.c print_arg_int.c print_arg_unsigned.c print_string.c
OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
