# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: wperu <marvin@le-101.fr>                   +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/07 14:33:16 by wperu        #+#   ##    ##    #+#        #
#    Updated: 2020/01/26 03:29:19 by wperu       ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

SRCS    = ft_convert_di.c \
		  ft_convert_p.c \
		  ft_convert_c.c  \
		  ft_convert_s.c  \
		  ft_convert_x.c \
		  ft_convert_u.c \
		  ft_convert.c \
		  ft_utils.c \
		  ft_printf.c 

LIBFT   = libft/

LIBFT_MAKE = make -C libft/

OBJS    = $(SRCS:.c=.o)

NAME    = libftprintf.a

INCLUDE = ft_printf.h

CC      = gcc

CFLAGS  = -Wall -Wextra -Werror

RM      = rm -rf

$(NAME):    $(OBJS) $(INCLUDE) 
	        $(LIBFT_MAKE)
			cp libft/libft.a ./$(NAME)
			ar rcs $(NAME) $(OBJS) $(INCLUDE)


all:        $(NAME) $(INCLUDE)
	
%.o: %.c
	     $(CC) -I includes/ -o $@ -c $< $(CFLAGS)
clean:
	${RM} ${OBJS}
	make clean -C libft/

fclean:     clean
	        $(RM) $(NAME)
			make fclean -C $(LIBFT)

re:			fclean all
	
.PHONY:     all clean fclean re
