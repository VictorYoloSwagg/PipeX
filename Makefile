NAME		= pipex
LIBFTNAME 	= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LIBFTDIR 	= libft/
SRCS		= pipex_utils.c pipex.c
OBJS		= $(SRCS:.c=.o)

all:	$(NAME)

# Compilation de la libft
makelibft:
	@make -C $(LIBFTDIR)

# Compilation de l'exécutable pipex
$(NAME): makelibft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFTDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean $(NAME)

.PHONY:	all clean fclean re