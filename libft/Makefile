# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/24 03:09:03 by smoreno-          #+#    #+#              #
#    Updated: 2020/02/23 16:13:04 by mvo-van-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	libft.a
SRC			=	ft_memset.c         \
				ft_bzero.c          \
				ft_memcpy.c         \
				ft_memccpy.c        \
				ft_memmove.c        \
				ft_memchr.c         \
				ft_memcmp.c         \
				ft_strlen.c         \
				ft_intlen.c         \
				ft_listlen.c        \
				ft_strdup.c         \
				ft_strcpy.c         \
				ft_strncpy.c        \
				ft_strcat.c         \
				ft_strncat.c        \
				ft_strlcat.c        \
				ft_strchr.c         \
				ft_strrchr.c        \
				ft_strstr.c         \
				ft_strnstr.c        \
				ft_strcmp.c         \
				ft_strncmp.c        \
				ft_atoi.c           \
				ft_isalpha.c        \
				ft_isspace.c        \
				ft_isdigit.c        \
				ft_isalnum.c        \
				ft_isascii.c        \
				ft_isprint.c        \
				ft_toupper.c        \
				ft_tolower.c        \
				ft_memalloc.c       \
				ft_memdel.c         \
				ft_strnew.c         \
				ft_strdel.c         \
				ft_strclr.c         \
				ft_striter.c        \
				ft_striteri.c       \
				ft_strmap.c         \
				ft_strmapi.c        \
				ft_strequ.c         \
				ft_strnequ.c        \
				ft_strsub.c         \
				ft_strjoin.c        \
				ft_strtrim.c        \
				ft_strsplit.c       \
				ft_counter_words.c  \
				ft_sortinttab.c     \
				ft_itoa.c           \
				ft_putchar.c        \
				ft_putstr.c         \
				ft_puttab.c         \
				ft_putendl.c        \
				ft_putnbr.c         \
				ft_putchar_fd.c     \
				ft_putstr_fd.c      \
				ft_putendl_fd.c     \
				ft_putnbr_fd.c      \
				ft_lstnew.c         \
				ft_lstdelone.c      \
				ft_lstdel.c         \
				ft_convert.c\
				parser.c\
				ft_printf.c \
				ft_wchar.c\
				flags.c \
				utils.c \
				utils2.c \
				numb_convert.c \
				tools.c \
				tools2.c \
				pading.c \
				float.c \
				lst.c  \
				ft_printf.c \

OBJ     =     $(SRC:.c=.o)

FLAGS     =  -Wall -Werror -Wextra -I ../includes

all: $(NAME) ../includes/

$(NAME): $(OBJ)
	@ar rcs $(NAME) $^   

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $<

re: fclean all

clean:
	@/bin/rm -Rf $(OBJ)

fclean: clean
	@/bin/rm -Rf $(NAME)
.PHONY : all, $(NAME), clean, fclean, re
