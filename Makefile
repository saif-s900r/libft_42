NAME	= libft.a
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
AR	= ar rcs

SRCS	= $(filter-out main.c, $(wildcard *.c))
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test : $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) -o test
	./test

.PHONY: all clean fclean re test 
