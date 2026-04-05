CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rc
RM = rm -f

SOURCES = main.c change_input.c check_input.c from_libft.c moves.c sorting_small_stack.c \
          sorting.c tools1.c ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunsigned.c \
          ft_puthex.c ft_putptr.c moves2.c ft_fill.c ft_split.c from_libft2.c parsing_input.c get_next_line_utils.c
OBJECT = $(SOURCES:.c=.o)

BSOURCES = checker.c get_next_line.c get_next_line_utils.c change_input.c check_input.c from_libft.c \
           moves.c sorting_small_stack.c sorting.c tools1.c ft_printf.c ft_putchar.c ft_putstr.c \
           ft_putnbr.c ft_putunsigned.c ft_puthex.c ft_putptr.c moves2.c ft_fill.c ft_split.c from_libft2.c\
		    parsing_input.c

BOBJECT = $(BSOURCES:.c=.o)

NAME = push_swap
BNAME = checker

all: $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BNAME)

$(BNAME): $(BOBJECT)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJECT) $(BOBJECT)

fclean: clean
	$(RM) $(NAME) $(BNAME)

re: fclean all bonus

.PHONY: clean