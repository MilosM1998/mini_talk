# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmilicev <mmilicev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/07 14:09:47 by mmilicev          #+#    #+#              #
#    Updated: 2024/11/20 19:53:04 by mmilicev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
FTP = ft_printf/

LIBFT_SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
	  ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c  \
	  ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c  \
	  ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putchar_fd.c ft_putnbr_fd.c ft_itoa.c ft_split.c \
	  ft_strmapi.c ft_striteri.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
	  ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

FT_PRINTF_SRC = $(FTP)ft_printf.c $(FTP)ft_print_uint.c $(FTP)ft_printf_utils.c $(FTP)ft_printhex.c $(FTP)ft_printp.c 

SRC = $(LIBFT_SRC) $(FT_PRINTF_SRC)

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) 
	$(AR) $(NAME) $(OBJ)

$(FTP)%.o: $(FTP)%.c
	$(CC) -c $(CFLAGS) $< -o $@

%.o: %.c
	$(CC) -c  $(CFLAGS) $<

all: $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
