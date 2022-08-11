# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchee <nchee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 16:30:03 by nchee             #+#    #+#              #
#    Updated: 2022/08/11 19:02:45 by nchee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Libft.a
INCLUDES	= include
SRCS_DIR	= srcs/
OBJS_DIR	= objs/
MAIN_DIR	= $(shell pwd)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I
AR			= ar -rcs
RM			= rm -f

DEF_COLOUR	= \033[0;39m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m

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

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS)
			@echo "$(GREEN)Libft Complied$(DEF_COLOR)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOUR)"
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJF):	
			@mkdir -p $(OBJS_DIR)
			@mkdir -p $(OBJS_DIR)$(DIR_LIBFT)
			@mkdir -p $(OBJS_DIR)$(DIR_PRINTF)

clean:
			@$(RM) -rf $(OBJS_DIR)
			@echo "$(GREEN)Libft Object Files Cleaned$(DEF_COLOR)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(GREEN)Libft Exec Files Cleaned$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)Libft Cleaned and Rebuilt Everything$(DEF_COLOR)"

.PHONY:		all clean fclean re
