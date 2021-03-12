# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 17:51:38 by cromalde          #+#    #+#              #
#    Updated: 2021/03/12 16:41:46 by cromalde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#		 -*- Makefile -*-

CKNAME	=	checker
PSNAME	=	push_swap
CKR		=	chsrcs/checker.c \
			chsrcs/chck_utils.c

PSS		=	ps_sw_srcs/push_swap.c \
			ps_sw_srcs/ps_sw_utils.c \
			ps_sw_srcs/insertion_sort.c

INSTR	=	instruction/pa_pb.c \
			instruction/ra_rb.c \
			instruction/rra_rrb.c \
			instruction/sa_sb.c

INCCK	=	includes/checker.h \
			includes/instruction.h

INCPS	=	includes/push_swap.h \
			includes/instruction.h
			
OBCKR	=	$(CKR:.c=.o)

OBPSS	=	$(PSS:.c=.o)

OBIST	=	$(INSTR:.c=.o)

CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror -g
MKDIR	=	mkdir -p
RM		=	rm -rf

.PHONY:	all clean fclean re

all: $(CKNAME) $(PSNAME)

$(OBIST):
	@$(CC) $(CFLAG) -c $(INSTR)
	@mv *.o instruction/

$(OBCKR): $(OBIST)
	@$(CC) $(CFLAG) -c $(CKR)
	mv *.o chsrcs/

$(OBPSS): $(OBIST)
	@$(CC) $(CFLAG) -c $(PSS)
	@mv *.o ps_sw_srcs/

$(CKNAME):	$(OBCKR)
	@make bonus -C ./libft
	@echo "\033[0;32mCreating        libft.a   \033[0;0m"
	@$(CC) $(CFLAGS) $(OBCKR) $(OBIST) ./libft/libft.a -o $(CKNAME)
	@echo "\033[0;32mCreating        CHECKER\033[0;0m"

$(PSNAME):	$(OBPSS)
	@make bonus -C ./libft
	@$(CC) $(CFLAGS) $(OBPSS) $(OBIST) ./libft/libft.a -o $(PSNAME)
	@echo "\033[0;32mCreating        PUSH_SWAP\033[0;0m"

clean:
	@make clean -C ./libft
	@$(RM) $(OBCKR) $(OBPSS) $(OBIST)
	@echo "\033[0;31mCleaning	Objects\033[0;0m"

fclean:	clean
	@make fclean -C ./libft
	@$(RM) $(CKNAME) $(PSNAME)
	@echo "\033[0;31mRemoving	executables\033[0;0m"

re:	fclean all