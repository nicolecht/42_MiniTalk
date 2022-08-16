# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchee <nchee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 16:30:03 by nchee             #+#    #+#              #
#    Updated: 2022/08/16 17:21:26 by nchee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/bash

NAME		= MiniTalk.a
CLIENT		= client
SERVER		= server
INCLUDES	= -I include
LIBFT		= Libft
LIBFT_LIB	= Libft.a
SRCS_DIR	= srcs/
OBJS_DIR	= objs/
MAIN_DIR	= $(shell pwd)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar -rcs
RM			= rm -f
ECHO		= echo -e

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

SRCS_FILES_CL = client
SRCS_FILES_SV = server

SRCS_CL		= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES_CL)))
OBJS_CL		= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES_CL)))

SRCS_SV		= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES_SV)))
OBJS_SV		= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES_SV)))

OBJF		= .cache_exists

start:		
			@make -C $(LIBFT)
			@cp Libft/Libft.a $(MAIN_DIR)
			@$(ECHO) -n "$(YELLOW)[MINITALK]:\t$(DEF_COLOR)"
			@$(ECHO) -n "$(RED)[$(DEF_COLOR)"
			@make all

all:		$(CLIENT) $(SERVER)

$(CLIENT):	$(OBJS_CL) $(OBJF)
			@$(CC) $(CFLAGS) $(OBJS_CL) $(INCLUDES) $(LIBFT_LIB) -o $(CLIENT)

$(SERVER):	$(OBJS_SV) $(OBJF)
			@$(ECHO) -n "$(RED)]$(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(OBJS_SV) $(INCLUDES) $(LIBFT_LIB) -o $(SERVER)
			@$(ECHO) "$(GREEN) => MiniTalk Complied$(DEF_COLOR)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJF)
			@$(ECHO) -n "$(ORANGE)=$(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJF):	
			@mkdir -p $(OBJS_DIR)

clean:
			@$(RM) -rf $(OBJS_DIR)
			@$(RM) $(OBJF)
			@make clean -C $(LIBFT)
			@$(ECHO) -n "$(BLUE)[MINITALK]:\tobject files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"

fclean:		clean
			@$(RM) $(CLIENT) $(SERVER)
			@$(RM) $(LIBFT_LIB)
			@$(RM) $(LIBFT)/Libft.a
			@$(ECHO) -n "$(CYAN)[LIBFT]:\texec. files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"
			@$(ECHO) -n "$(CYAN)[MINITALK]:\texec. files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"

re:			fclean start
			@$(ECHO) -n "$(MAGENTA)[MINITALK]:\tCleaned and Rebuilt\n$(DEF_COLOR)"

.PHONY:		start all clean fclean re
