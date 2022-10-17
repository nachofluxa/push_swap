NAME := push_swap
LIBFT_NAME = libft.a

SRCS =	push_swap.c \
		aux.c \
		mount_stack.c \
		push_or_swap.c \
		rotate.c \
		reverse_rotate.c \
		sort_big_stack.c \
		errors.c

OBJS = ${SRCS:.c=.o}

LIBFT_DIR := ./libft/
INC_DIR := ./header/
EXE_DIR = ./

CC := cc
GCC := gcc
CFLAGS := -Wall -Wextra -Werror -fsanitize=address -g3
MV := mv -f
RM := rm -f

%.o: %.c
	$(CC)  $(CFLAGS) -c $< -I $(INC_DIR) -o $@ 

$(NAME): $(LIBFT_DIR)$(LIBFT_NAME) $(OBJS)
	$(CC) -fsanitize=address -o $(NAME)  $^ -I $(INC_DIR)

$(LIBFT_DIR)$(LIBFT_NAME): $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re