NAME		= libft.a
SO_NAME	= libft.so
CC		= cc
AR		= ar rcs
CFLAGS		= -Wall -Wextra -Werror

SRCS		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isprint.c \
		  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		  ft_toupper.c ft_tolower.c ft_strchr.c ft_putchar_fd.c \
		  ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
		  ft_atoi.c ft_strdup.c ft_substr.c ft_putstr_fd.c ft_strtrim.c \
		  ft_strlcpy.c ft_isascii.c ft_strjoin.c ft_putnbr_fd.c \
		  ft_strlcat.c ft_strnstr.c ft_calloc.c ft_putendl_fd.c \
		  ft_itoa.c ft_split.c ft_strmapi.c ft_striteri.c
OBJS		= $(SRCS:.c=.o)

BONUS_SRCS	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c \
		  ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstsize_bonus.c \
		  ft_lstadd_back_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

.PHONY: all bonus clean fclean re so

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(NAME) $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -I . -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(SO_NAME)

re: fclean all

so: $(OBJS)
	$(CC) -shared -o $(SO_NAME) $(OBJS)
