# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cromalde <cromalde@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 17:51:38 by cromalde          #+#    #+#              #
#    Updated: 2021/03/20 12:49:54 by cromalde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#		 -*- Makefile -*-

CKNAME	=	checker
PSNAME	=	push_swap
LIB		=	libft/libft.a
CKR		=	chsrcs/checker.c \
			chsrcs/chck_utils.c \
			chsrcs/bonus_utils.c

PSS		=	ps_sw_srcs/push_swap.c \
			ps_sw_srcs/ps_sw_utils.c \
			ps_sw_srcs/ps_sw_utils2.c \
			ps_sw_srcs/insertion_sort.c \
			ps_sw_srcs/insertion_utils.c \
			ps_sw_srcs/quick_sort.c \
			ps_sw_srcs/find_max_seq.c \
			ps_sw_srcs/push_not_seq.c \
			ps_sw_srcs/best_move_loop.c \
			ps_sw_srcs/exec_best_move.c \
			ps_sw_srcs/r_rr_loop.c\
			ps_sw_srcs/quick_utils.c \
			ps_sw_srcs/quick_utils2.c

INSTR	=	instruction/pa_pb.c \
			instruction/ra_rb.c \
			instruction/rra_rrb.c \
			instruction/sa_sb.c \
			instruction/common_utils.c

O_IN	=	$(INSTR:.c=.o)
O_CK	=	$(CKR:.c=.o)
O_PS	=	$(PSS:.c=.o)

H_INS	=	-I includes/instruction.h

INCCK	=	-I includes/checker.h

INCPS	=	-I includes/push_swap.h

CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror -g
RM		=	rm -rf

.PHONY:		all clean fclean re bonus common

all:	$(LIB) common $(CKNAME) $(PSNAME)

$(LIB):
	@make bonus -C ./libft

common:
	@$(CC) $(CFLAG) -c $(H_INS) $(INSTR)
	@mv *a_*.o instruction/
	@mv common_utils* instruction/

$(CKNAME):
	@$(CC) -c $(CFLAG) $(INCCK) $(CKR)
	@mv checker.o chsrcs/
	@mv chck_utils.o chsrcs/
	@mv bonus_utils.o chsrcs/
	@$(CC) -o $(CKNAME) $(CFLAG) $(H_INS) $(INCCK) $(O_IN) $(O_CK) $(LIB)
	@echo "\033[0;32mCreating        $(CKNAME)\033[0;0m"

$(PSNAME):
	@$(CC) -c $(CFLAG) $(INCPS) $(PSS)
	@mv *.o ps_sw_srcs/
	@$(CC) -o $(PSNAME) $(CFLAG) $(H_INS) $(INCPS) $(O_IN) $(O_PS) $(LIB)
	@echo "\033[0;32mCreating        $(PSNAME)\033[0;0m"

clean:
	@make clean -C ./libft
	@$(RM) $(O_CK) $(O_IN) $(O_PS)
	@echo "\033[0;31mCleaning        folder objs\033[0;0m"


fclean:	clean
	@make fclean -C ./libft
	@$(RM) $(CKNAME) $(PSNAME)
	@echo "\033[0;31mRemoving          binaries\033[0;0m"

re: fclean all
