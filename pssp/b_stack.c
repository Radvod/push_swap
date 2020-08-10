/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 13:04:50 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/05 14:42:48 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pssp.h"

int			is_order(int *stack_a)
{
	int max;
	int min;

	max = find_max(stack_a, 0);
	min = find_min(stack_a, 0);
	if (stack_a[stack_a[0]] == min && stack_a[stack_a[0] - 1] == max)
		print_command("sa", stack_a, NULL);
	if (stack_a[stack_a[0]] == max && stack_a[1] == min)
	{
		print_command("rra", stack_a, NULL);
		print_command("sa", stack_a, NULL);
	}
	return (stack_a[stack_a[0]] == max || stack_a[stack_a[0]] == min\
	|| (stack_a[stack_a[0]] > stack_a[1] &&
	stack_a[stack_a[0]] < stack_a[stack_a[0] - 1]));
}

static int	is_order_two_first(int *stack_a)
{
	return ((stack_a[stack_a[0] - 2] > stack_a[stack_a[0] - 1]\
	&& stack_a[stack_a[0]] < stack_a[stack_a[0] - 1]) && (is_order(stack_a)));
}

int			sa_work(int *stack_a, int *stack_b)
{
	int res;
	int max;
	int min;
	int dist;

	max = find_max(stack_a, 1);
	min = find_min(stack_a, 1);
	dist = MAX(min, max) - MIN(min, max);
	if ((max >= stack_a[0] - 1 || min >= stack_a[0] - 1)\
	&& (dist == 1))
		return (0);
	commander("sa", stack_a, stack_b);
	res = is_order_two_first(stack_a);
	commander("sa", stack_a, stack_b);
	return (res);
}

int			push_from_b(int *stack_a, int *stack_b)
{
	if (!stack_b[0])
		return (0);
	if (stack_b[stack_b[0]] > stack_a[1] &&\
	stack_b[stack_b[0]] < stack_a[stack_a[0]])
		print_command("pa", stack_a, stack_b);
	else if (stack_b[stack_b[0] - 1] > stack_a[1] &&\
	stack_b[stack_b[0] - 1] < stack_a[stack_a[0]] && stack_b[0] > 1)
	{
		print_command("rb", stack_a, stack_b);
		print_command("pa", stack_a, stack_b);
	}
	else if (stack_b[1] > stack_a[1] && stack_b[1] < stack_a[stack_a[0]])
	{
		print_command("rrb", stack_a, stack_b);
		print_command("pa", stack_a, stack_b);
	}
	else
		return (0);
	return (1);
}

void		work_b(int *stack_a, int *stack_b)
{
	while (!a_sort(stack_a))
	{
		while (push_from_b(stack_a, stack_b))
			;
		if (is_order(stack_a))
			print_command("ra", stack_a, stack_b);
		else if (sa_work(stack_a, stack_b))
			print_command("sa", stack_a, stack_b);
		else
			print_command("pb", stack_a, stack_b);
	}
}
