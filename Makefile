# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialdidi <ialdidi@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 15:34:00 by ialdidi           #+#    #+#              #
#    Updated: 2023/11/11 08:26:51 by ialdidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC				= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
				ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_toupper.c \
				ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
				ft_atoi.c ft_calloc.c ft_strdup.c ft_strlcpy.c ft_strlcat.c \
				ft_strnstr.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
				ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c

OBJS 			= $(SRC:.c=.o)

BONUS			= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS 		= $(BONUS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.
ARC				= ar rcs

LIBRARY			= libft.h
NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				$(ARC) $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

%.o : %.c		$(LIBRARY)
				$(CC) $(CFLAGS) -o $@ -c $<
				
bonus:			$(OBJS) $(BONUS_OBJS)
				$(ARC) $(NAME) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)
				
re:				fclean all bonus