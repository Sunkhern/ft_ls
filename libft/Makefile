# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wromano <wromano@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 16:04:15 by wromano           #+#    #+#              #
#    Updated: 2014/11/12 18:00:02 by wromano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c		ft_itoa.c \
	   ft_lstnew.c		ft_lstdelone.c \
	   ft_isalnum.c		ft_isalpha.c	ft_isascii.c		ft_isblank.c \
	   ft_iscntrl.c		ft_isdigit.c	ft_isgraph.c		ft_isprint.c \
	   ft_ispunct.c		ft_isspace.c	ft_isxdigit.c \
	   ft_memalloc.c	ft_memccpy.c	ft_memchr.c			ft_memcmp.c \
	   ft_memcpy.c		ft_memdel.c		ft_memmove.c		ft_memset.c \
	   ft_bzero.c \
	   ft_putchar.c		ft_putchar_fd.c	ft_putendl.c		ft_putnbr.c \
	   ft_putendl_fd.c	ft_putnbr_fd.c	ft_putstr.c			ft_putstr_fd.c \
	   ft_strcat.c		ft_strchr.c		ft_strclr.c			ft_strcmp.c \
	   ft_strcpy.c		ft_strdel.c		ft_strdup.c			ft_strequ.c \
	   ft_striter.c		ft_striteri.c	ft_strjoin.c		ft_strlcat.c \
	   ft_strlen.c		ft_strmap.c		ft_strmapi.c		ft_strncat.c \
	   ft_strncmp.c		ft_strncpy.c	ft_strnequ.c		ft_strnew.c \
	   ft_strnstr.c		ft_strrchr.c	ft_strstr.c			ft_strsub.c \
	   ft_strtrim.c \
	   ft_tolower.c		ft_toupper.c \

OBJ = $(patsubst %.c, %.o, $(SRCS))

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	gcc -c $(CFLAGS) $< -o $@

all: $(NAME)
	@echo "\x1b[32;01m          ===== Compilation is complete ===="
	@echo "\x1b[32;39m          = Program is ready for initation ="

$(NAME): $(OBJ)
	ar rc  $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

proper: all clean

re: fclean all
