SRCS			= $(shell find *.c)
OBJS 			= $(SRCS:.c=.o)
CFLAGS			= -Wall -Wextra -Werror
ARC				= ar rc
NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
	@$(ARC) $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

%.o 			: %.c libft.h
	@$(CC) $(CFLAGS) -o $@ -c $<

fclean:			clean
	@$(RM) $(NAME)
				
re:	fclean all