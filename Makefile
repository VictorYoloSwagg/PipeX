NAME        = pipex
LIBFTNAME   = libft.a
LIBFTDIR    = libft/
LIBFT       = $(LIBFTDIR)$(LIBFTNAME)
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g
SRCS        = main.c free.c path.c errors.c
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -o $(NAME)

$(OBJS): | makelibft

makelibft:
	@make -C $(LIBFTDIR)

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFTDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re makelibft