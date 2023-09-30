NAME = libftprintf.a
CC = cc
CFRAGS = -Wall -Wextra -Werror
INCLUDES = -I ./ -I ./libft/
LIBFT = libft.a
LIBFT_DIR = ./libft/
LIBFT_A = $(addprefix $(LIBFT_DIR), $(LIBFT))
SRCS = ft_printf.c \
	ft_printf_utils.c \
	solve_format_chars.c \
	solve_format_num.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp -f $(LIBFT_A) $(NAME)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

$(LIBFT):
	make -C ./libft

$(OBJS): %.o: %.c
	$(CC) $(CFRAGS) $(INCLUDES) -c $< -o $@

test:
	$(CC) -Wall -Wextra test.c -L./ -lftprintf

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME) a.out

re: fclean all

.PHONY: all clean fclean re