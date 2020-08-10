# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 14:29:03 by hgalazza          #+#    #+#              #
#    Updated: 2020/08/05 17:25:43 by hgalazza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER=checker

PS_SP=push_swap

CH_FILES=check/command_work.c check/main.c

CH_OBJ=$(CH_FILES:.c=.o)

PSSP_FILES=pssp/a_sorted.c pssp/b_stack.c pssp/find_minmax.c pssp/main.c pssp/rot.c pssp/sorter.c \
			pssp/turn_checker.c check/command_work.c

PSSP_OBJ=$(PSSP_FILES:.c=.o)

COM=commands/push.c commands/rev_rot.c commands/rotate.c commands/swap.c

COM_OBJ=$(COM:.c=.o)

IN_STACK=init_stacks/er_wrk.c init_stacks/ft_duplicate.c init_stacks/ft_stacks.c \
			init_stacks/init_stacks.c

IN_STACK_OBJ=$(IN_STACK:.c=.o)

UTILS=utils/flags.c utils/ft_atoi_long.c utils/ft_error.c utils/printer.c \
		utils/sorted.c

UTILS_OBJ=$(UTILS:.c=.o)

FLAGS=-Wall -Wextra -Werror

INCLUDES=libft/libft.a

all: $(NAME)
	@make -C libft/ all
	@gcc -o $(CHECKER) $(FLAGS) $(CH_FILES) $(COM) $(IN_STACK) $(UTILS) $(INCLUDES)
	@gcc -o $(PS_SP) $(FLAGS) $(PSSP_FILES) $(COM) $(IN_STACK) $(UTILS) $(INCLUDES)

clean:
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(CHECKER)
	@/bin/rm -f $(PS_SP)
	@make -C libft/ fclean

re: fclean all

push_swap:
	@gcc -o $(PS_SP) $(FLAGS) $(COM) $(IN_STACK) $(UTILS) $(INCLUDES) $(PSSP_FILES)

checker:
	@gcc -o $(CHECKER) $(FLAGS) $(CH_FILES) $(COM) $(IN_STACK) $(UTILS) $(INCLUDES)

.PHONY: all, clean, fclean, re, push_swap, checker