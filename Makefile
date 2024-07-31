NAME	= pipex.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

SRCS	= pipex_utils.c pipex.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re