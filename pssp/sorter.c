/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:46:01 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/05 13:19:18 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pssp.h"

void	push_best(int *stack_a, int *stack_b)
{
	int index;

	index = get_best_index(stack_a, stack_b);
	rot(stack_a, stack_b, index);
	print_command("pa", stack_a, stack_b);
}

void	stack_sort(int *stack_a, int *stack_b)
{
	int i_min;

	while (stack_b[0] > 0)
		push_best(stack_a, stack_b);
	i_min = find_min(stack_a, 1);
	if (i_min <= stack_a[0] / 2)
	{
		while (i_min--)
			print_command("rra", stack_a, stack_b);
	}
	else
	{
		i_min = stack_a[0] - i_min;
		while (i_min--)
			print_command("ra", stack_a, stack_b);
	}
}
