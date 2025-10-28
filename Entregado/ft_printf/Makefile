NAME		= libftprintf.a
CC		= cc
AR		= ar rcs
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I . -I libft

SRCS		= ft_printf.c \
		  ft_format.c \
		  ft_parse_and_handle_funcs.c \
		  ft_printf_funcs.c \
		  ft_ptr.c \
		  ft_utility_funcs.c \
		  ft_str_helpers.c
OBJS		= $(SRCS:.c=.o)

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

bonus: all
