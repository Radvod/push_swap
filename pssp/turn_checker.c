/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 12:21:32 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/05 14:41:03 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pssp.h"

int		turn_rb(int *stack_b, int n_from_b)
{
	int i;

	i = 1;
	while (stack_b[i] != n_from_b)
		i++;
	return (i <= stack_b[0] / 2) ? i : stack_b[0] - i;
}

int		turn_ra(int *stack_a, int nbr)
{
	int i;

	i = stack_a[0];
	if (nbr > stack_a[1] && nbr < stack_a[stack_a[0]])
		return (0);
	while (i > 1)
	{
		if (nbr > stack_a[i] && nbr < stack_a[i - 1])
			return (i > stack_a[0] / 2) ?\
			(stack_a[0] - (i - 1)) : i - 1;
		i--;
	}
	return (10000);
}

int		turn_counter(int *stack_a, int *stack_b)
{
	int i;
	int	*turns;
	int a;
	int b;

	if (stack_b[0] < 2)
		return (stack_b[0]);
	turns = init_b(stack_b[0] + 1);
	turns[0] = stack_b[0];
	i = 1;
	while (i <= stack_b[0])
	{
		a = turn_ra(stack_a, stack_b[i]);
		b = turn_rb(stack_b, stack_b[i]);
		turns[i] = a + b;
		i++;
	}
	i = find_min(turns, 1);
	free(turns);
	return (i);
}

int		get_best_index(int *stack_a, int *stack_b)
{
	int index;

	index = turn_counter(stack_a, stack_b);
	return (index);
}
