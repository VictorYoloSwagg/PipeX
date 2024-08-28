NAME		= pipex
LIBFTNAME 	= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
LIBFTDIR 	= libft/
SRCS		= main.c free.c path.c errors.c
OBJS		= $(SRCS:.c=.o)

all:	$(NAME)

makelibft:
	@make -C $(LIBFTDIR)

$(NAME): makelibft $(OBJS)
	$(CC)  $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFTDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean $(NAME)

.PHONY:	all clean fclean re
