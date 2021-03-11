# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 17:51:38 by cromalde          #+#    #+#              #
#    Updated: 2021/03/11 18:29:17 by cromalde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#		 -*- Makefile -*-

CKNAME	=	checker
PSNAME	=	push_swap
CKR		=	./checker/$(wildcard *.c)
PSS		=	./push_swap/$(wildcard *.c)
INCCK	=	./includes/checker.h
INCPS	=	./includes/push_swap.h
CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror -g
MKDIR	=	mkdir -p
RM		=	rm -rf
OCK_DIR	=	ocks
OPS_DIR	=	opss
OBCKR	=	$(addprefix $(OCK_DIR)/, $(CKR: .c=.o)
OBPSS	=	$(addprefix $(OPS_DIR)/, $(PSS: .c=.o)

.PHONY:	all clean fclean re

all: $(CKNAME) #$(PSNAME)

$(OCK_DIR)/%.o : %.c
	@$(MKDIR) $(OCK_DIR)
	@$(CC) $(CFLAG) -c $(CKR) -o $(CKNAME)
	@printf "Compiling... %-33.33s\r" $(CKNAME)

$(OPS_DIR)/%.o : %.c
	@$(MKDIR) $(OPS_DIR)
	@$(CC) $(CFLAG) -c $(PSS) -o $(PSNAME)
	@printf "Compiling... %-33.33s\r" $(PSNAME)

$(CKNAME):	$(OBCKR)
	@make bonus -C ./libft
	@echo "\033[0;32mCreating        libft.a   \033[0;0m"
	@$(CC) $(CFLAGS) $(OBCKR) ./libft/libft.a -o $(CKNAME)
	@echo "\033[0;32mCreating        CHECKER\033[0;0m"

$(PSNAME):	$(OBPSS)
	@make bonus -C ./libft
	@echo "\033[0;32mCreating        libft.a   \033[0;0m"
	@$(CC) $(CFLAGS) $(OBPSS) ./libft/libft.a -o $(PSNAME)
	@echo "\033[0;32mCreating        PUSH_SWAP\033[0;0m"

clean:
	@make clean -C ./libft
	@$(RM) $(OCK_DIR) $(OPS_DIR)
	@echo "\033[0;31mCleaning	folders\033[0;0m"

fclean:	clean
	@make fclean -C ./libft
	@$(RM) $(CKNAME) $(PSNAME)
	@echo "\033[0;31mRemoving	executables\033[0;0m"

re:	fclean all