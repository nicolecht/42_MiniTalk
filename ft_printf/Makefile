# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchee <nchee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 16:30:03 by nchee             #+#    #+#              #
#    Updated: 2022/08/11 17:50:36 by nchee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
INCLUDES	= include
LIBFT		= libft
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

SRCS_FILES	= ft_printf ft_printstr ft_printptr ft_printnbr \
				ft_printunsigned ft_printhex ft_printpercent

SRCS		= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))

OBJS		= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))

OBJF		= .cache_exists

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C $(LIBFT)
			@cp libft/libft.a $(MAIN_DIR)
			@mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJS)
			@echo "$(GREEN)ft_printf Complied$(DEF_COLOR)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOUR)"
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJF):	
			@mkdir -p $(OBJS_DIR)

clean:
			@$(RM) -rf $(OBJS_DIR)
			@make clean -C $(LIBFT)
			@echo "$(GREEN)ft_printf Object Files Cleaned$(DEF_COLOR)"

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(LIBFT)/libft.a
			@echo "$(GREEN)ft_printf Exec Files Cleaned$(DEF_COLOR)"
			@echo "$(GREEN)Libft Exec File Cleaned$(DEF_COLOR)"

re:			fclean all
			@echo "$(GREEN)ft_printf Cleaned and Rebuilt Everything$(DEF_COLOR)"

.PHONY:		all clean fclean re
