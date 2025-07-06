NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

MY_SOURCES =	main.c \
				create_stack.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

PRINTF_DIR = libft/printf
LIBFT_DIR = libft

PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBS = $(PRINTF_LIB) $(LIBFT_LIB)

all: $(NAME)

$(NAME): $(MY_OBJECTS) $(LIBS)
	$(CC) $(CFLAGS) -o $@ $(MY_OBJECTS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(MY_OBJECTS)
	-$(MAKE) -C $(PRINTF_DIR) clean
	-$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	-$(MAKE) -C $(PRINTF_DIR) fclean
	-$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
