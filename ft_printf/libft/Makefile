# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchee <nchee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 14:23:15 by nchee             #+#    #+#              #
#    Updated: 2022/08/11 18:07:24 by nchee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
INCLUDES= ../include
SRCS_DIR= srcs/
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I
LIB1	= ar -rcs
RM		= rm -f

DEF_COLOR = \033[0;39m
GREEN	= \033[0;92m
YELLOW		= \033[0;93m

SRCS_FILES		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
			ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS	= $(SRCS:.c=.o)

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
			@$(LIB1) $(NAME) $(OBJS)
			@echo "$(GREEN)Libft Complied$(DEF_COLOR)"

bonus:		$(NAME) $(BONUS_OBJS)
			$(LIB1) $(NAME) $(BONUS_OBJS)

.c.o:
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOUR)"
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJS) $(BONUS_OBJS)
			@echo "$(GREEN)Libft Object Files Cleaned$(DEF_COLOR)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(GREEN)Libft Exec Files Cleaned$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Libft Cleaned and Rebuilt Everything$(DEF_COLOR)"

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus