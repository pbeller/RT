# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbeller <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/27 15:58:54 by pbeller           #+#    #+#              #
#    Updated: 2016/11/27 15:58:57 by pbeller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

OBJ =	ft_putchar.o \
		ft_putchar_fd.o \
		ft_putstr.o \
		ft_putstr_fd.o \
		ft_putendl.o \
		ft_putendl_fd.o \
		ft_putnbr.o \
		ft_putnbr_fd.o \
		ft_itoa.o \
		ft_strlen.o \
		ft_atoi.o \
		ft_strstr.o \
		ft_strnstr.o \
		ft_strcmp.o \
		ft_strncmp.o \
		ft_strdup.o \
		ft_strcpy.o \
		ft_strncpy.o \
		ft_strcat.o \
		ft_strncat.o \
		ft_strlcat.o \
		ft_strchr.o \
		ft_strrchr.o \
		ft_isalpha.o \
		ft_isdigit.o \
		ft_isalnum.o \
		ft_isascii.o \
		ft_isprint.o \
		ft_toupper.o \
		ft_tolower.o \
		ft_memset.o \
		ft_bzero.o \
		ft_memcpy.o \
		ft_memccpy.o \
		ft_memmove.o \
		ft_memchr.o \
		ft_memcmp.o \
		ft_memalloc.o \
		ft_memdel.o \
		ft_strnew.o \
		ft_strdel.o \
		ft_strclr.o \
		ft_striter.o \
		ft_striteri.o \
		ft_strmap.o \
		ft_strmapi.o \
		ft_strequ.o \
		ft_strnequ.o \
		ft_strsub.o \
		ft_strjoin.o \
		ft_strjoinfree.o \
		ft_strtrim.o \
		ft_strsplit.o \
		ft_lstnew.o \
		ft_lstdelone.o \
		ft_lstdel.o \
		ft_lstadd.o \
		ft_lstiter.o \
		ft_lstmap.o \
		ft_lst_push_back.o \
		ft_strrev.o \
		ft_size_int.o \
		ft_is_white_space.o \
		ft_is_lowercase.o \
		ft_is_uppercase.o \
		ft_lstlen.o \
		get_next_line.o \
		ft_point.o \
		ft_dpoint.o \
		ft_dcomplex.o \
		ft_abs.o \
		ft_x_malloc.o

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ) && ranlib libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean
