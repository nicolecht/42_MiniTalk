# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchee <nchee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 16:30:03 by nchee             #+#    #+#              #
#    Updated: 2022/08/16 17:21:27 by nchee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/bash

NAME		= Libft.a
INCLUDES	= include
SRCS_DIR	= srcs/
OBJS_DIR	= objs/
MAIN_DIR	= $(shell pwd)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I
AR			= ar -rcs
RM			= rm -f
ECHO		= echo -e

#Colors

DEF_COLOR	=	\033[0;39m
ORANGE		=	\033[0;33m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

#Sources

DIR_LIBFT	= libft/
LIBFT		= ft_isalpha ft_isdigit ft_isalnum ft_isascii \
			ft_isprint ft_strlen ft_memset ft_bzero \
			ft_memcpy ft_memmove ft_strlcpy ft_strlcat \
			ft_toupper ft_tolower ft_strchr ft_strrchr \
			ft_strncmp ft_memchr ft_memcmp ft_strnstr \
			ft_atoi ft_calloc ft_strdup ft_substr \
			ft_strjoin ft_strtrim ft_split ft_itoa \
			ft_strmapi ft_striteri ft_putchar_fd \
			ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
			ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast \
			ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter \
			ft_lstmap

DIR_PRINTF = ft_printf/
PRINTF		= ft_printf ft_printstr ft_printptr ft_printnbr \
				ft_printunsigned ft_printhex ft_printpercent

SRCS_FILES+=$(addprefix $(DIR_LIBFT),$(LIBFT))
SRCS_FILES+=$(addprefix $(DIR_PRINTF),$(PRINTF))

SRCS		= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))

OBJS		= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))

OBJF		= .cache_exists

start:		
			@echo -e -n "$(YELLOW)[LIBFT]:\t$(DEF_COLOR)"
			@echo -e -n "$(RED)[$(DEF_COLOR)"
			@make all

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@echo -e -n "$(RED)]$(DEF_COLOR)"
			@$(ECHO) "$(GREEN) => Libft Complied$(DEF_COLOR)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJF)
			@echo -e -n "$(ORANGE)=$(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJF):	
			@mkdir -p $(OBJS_DIR)
			@mkdir -p $(OBJS_DIR)$(DIR_LIBFT)
			@mkdir -p $(OBJS_DIR)$(DIR_PRINTF)

clean:
			@$(RM) -rf $(OBJS_DIR)
			@$(RM) $(OBJF)
			@$(ECHO) -n "$(BLUE)[LIBFT]:\tObject files$(DEF_COLOR)$(GREEN)  => Cleaned$(DEF_COLOR)\n"

fclean:		clean
			@$(RM) $(NAME)
			@$(ECHO) -n "$(CYAN)[LIBFT]:\tExec. files$(DEF_COLOR)$(GREEN)  => Cleaned$(DEF_COLOR)\n"

re:			fclean start
			@$(ECHO) -n "$(MAGENTA)[LIBFT]:\tCleaned and Rebuilt\n$(DEF_COLOR)"

.PHONY:		start all clean fclean re
