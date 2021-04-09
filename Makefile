# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 13:57:56 by ddiakova          #+#    #+#              #
#    Updated: 2021/04/09 15:35:32 by ddiakova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRCS 			= checker.c \
				ft_printf_utils.c \
				ft_x.c \
				ft_xx.c \
				ft_c.c \
				ft_s.c \
				ft_di.c \
				ft_u.c \
				ft_printf.c \
				ft_perc.c \
				ft_p.c \

OBJS			= $(SRCS:.c=.o)

RM 				= rm -f

CFLAGS 			= -Wall -Werror -Wextra -g -c

INCLUDE 		= \
		  		ft_printf.h

all:			$(NAME)

$(NAME):		$(OBJS) $(INCLUDE)
					ar rcs $(NAME) $(OBJS)

$(OBJS):		$(SRCS)
				gcc $(CFLAGS) $(SRCS) -I $(INCLUDE)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re: 			fclean all

test:			all
				gcc -Wall -Werror -Wextra printf-tester/main.c $(NAME)
				./a.out

.PHONY: 		all clean fclean re bonus
