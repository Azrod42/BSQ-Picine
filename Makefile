# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfantine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 20:02:48 by lfantine          #+#    #+#              #
#    Updated: 2022/08/30 18:50:27 by lfantine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_display_file

SCRS	=	main.c

OBJS	=	$(SCRS:.c=.o}

CC	=		gcc

CFLAGS	= 	-Wall -Wextra -Werror

${NAME}:
			${CC} ${CFLAGS} -o ${NAME} ${SCRS}

clean:
			rm -f *.o

fclean: 	clean
			rm -f ${NAME}

re:			fclean ${NAME}

.PHONY:		all clean fclean
