NAME		= pipex

LIBFTNAME 	= libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

LIBFTDIR 	= libft/

SRCS		= pipex_utils.c pipex.c

OBJS	= $(SRCS:.c=.o)

all:	$(NAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@chmod 777 pipex
	
clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean
	
fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean

re: fclean $(NAME)

.PHONY: all clean fclean re