# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchee <nchee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 16:30:03 by nchee             #+#    #+#              #
#    Updated: 2022/08/16 16:50:00 by nchee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
			@make all

all:		$(CLIENT) $(SERVER)

$(CLIENT):	$(OBJS_CL) $(OBJF)
			@$(CC) $(CFLAGS) $(OBJS_CL) $(INCLUDES) $(LIBFT_LIB) -o $(CLIENT)
			@echo "$(GREEN)Client Complied$(DEF_COLOR)"

$(SERVER):	$(OBJS_SV) $(OBJF)
			@$(CC) $(CFLAGS) $(OBJS_SV) $(INCLUDES) $(LIBFT_LIB) -o $(SERVER)
			@echo "$(GREEN)Server Complied$(DEF_COLOR)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOUR)"
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJF):	
			@mkdir -p $(OBJS_DIR)

clean:
			@$(RM) -rf $(OBJS_DIR)
			@$(RM) $(OBJF)
			@make clean -C $(LIBFT)
			@echo "$(GREEN)MiniTalk Object Files Cleaned$(DEF_COLOR)"

fclean:		clean
			@$(RM) $(CLIENT) $(SERVER)
			@$(RM) $(LIBFT_LIB)
			@$(RM) $(LIBFT)/Libft.a
			@echo "$(GREEN)Libft Exec Files Cleaned$(DEF_COLOR)"
			@echo "$(GREEN)MiniTalk Exec Files Cleaned$(DEF_COLOR)"

re:			fclean start
			@echo "$(GREEN)MiniTalk Cleaned and Rebuilt Everything$(DEF_COLOR)"

.PHONY:		start all clean fclean re
