# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 17:51:38 by cromalde          #+#    #+#              #
#    Updated: 2021/03/12 12:21:05 by cromalde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#		 -*- Makefile -*-

CKNAME	=	checker
PSNAME	=	push_swap
CKR		=	chsrcs/checker.c \
			chsrcs/chck_utils.c

PSS		=	push_swap/$(wildcard *.c)
OBPSS	=	$(addprefix $(OPS_DIR)/, $(PSS:%.c=%.o))

INSTR	=	instruction/pa_pb.c \
			instruction/ra_rb.c \
			instruction/rra_rrb.c \
			instruction/sa_sb.c

INCCK	=	includes/checker.h \
			includes/instruction.h

INCPS	=	includes/push_swap.h \
			includes/instruction.h
			
OBCKR	=	$(CKR:.c=.o)\
			$(INSTR:.c=.o)

CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror -g
MKDIR	=	mkdir -p
RM		=	rm -rf

.PHONY:	all clean fclean re

all: $(CKNAME) #$(PSNAME)

%.o: %.c
	@$(CC) $(CFLAG) -c $< -o $@
	@$(CC) $(CFLAG) -c $(INSTR)
	@mv *.o instruction/
	@printf "Compiling... %-33.33s\r" $@

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
	@$(RM) $(OBCKR)
	@echo "\033[0;31mCleaning	folders\033[0;0m"

fclean:	clean
	@make fclean -C ./libft
	@$(RM) $(CKNAME) $(PSNAME)
	@echo "\033[0;31mRemoving	executables\033[0;0m"

re:	fclean all