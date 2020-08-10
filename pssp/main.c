/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 11:44:59 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/05 14:22:23 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pssp.h"

void	print_command(char *cmd, int *stack_a, int *stack_b)
{
	ft_printf("%s\n", cmd);
	commander(cmd, stack_a, stack_b);
}

int		main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	int		i;
	t_pssp	flags;

	if (argc < 2)
		exit(1);
	i = flags_w(argv, &flags);
	argv += i;
	stack_a = init_a(argc - i, argv, flags.e);
	stack_b = init_b(stack_a[0] + 1);
	work_b(stack_a, stack_b);
	stack_sort(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
