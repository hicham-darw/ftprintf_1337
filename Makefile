CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

HEADER = libftprintf.h

LIBFT_HEADER = libft/libft.h

SRCS = ft_address_cat.c ft_charcat.c ft_decimal_cat.c ft_get_string.c ft_hexadecimal_cat.c \
       ft_onlyformat_cat.c ft_printf.c ft_strcat.c ft_uitoa.c get_len_printf.c printf_not_completed.c \
       len_hexa.c

OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft

all: $(NAME)

$(NAME): LIBFT $(OBJS)

LIBFT:
	@make -C $(LIBFT_DIR)

%.o:%.c $(HEADER) $(LIBFT_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT_DIR)
	ar rcs $(NAME) $@

clean: 
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: LIBFT clean
