/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 17:26:55 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/05 13:39:55 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pssp.h"

int		get_a_steps(int *stack_a, int nbr)
{
	int i;

	i = stack_a[0];
	if (nbr > stack_a[1] && nbr < stack_a[stack_a[0]])
		return (0);
	while (i > 1)
	{
		if (nbr > stack_a[i] && nbr < stack_a[i - 1])
			break ;
		i--;
	}
	return (i - 1);
}

void	b_rot(int *stack_a, int *stack_b, int steps)
{
	if (steps < stack_b[0] / 2)
	{
		while (steps--)
			print_command("rrb", stack_a, stack_b);
	}
	else
	{
		steps = stack_b[0] - steps;
		while (steps--)
			print_command("rb", stack_a, stack_b);
	}
}

void	a_rot(int *stack_a, int *stack_b, int steps)
{
	if (steps <= stack_a[0] / 2)
	{
		while (steps--)
			print_command("rra", stack_a, stack_b);
	}
	else
	{
		steps = stack_a[0] - steps;
		while (steps--)
			print_command("ra", stack_a, stack_b);
	}
}

void	rr_rotation(int *stack_a, int *stack_b, int a_steps, int b_steps)
{
	a_steps = stack_a[0] - a_steps;
	b_steps = stack_b[0] - b_steps;
	while (a_steps-- && b_steps--)
		print_command("rr", stack_a, stack_b);
	while (a_steps-- >= 0)
		print_command("ra", stack_a, stack_b);
	while (b_steps-- > 0)
		print_command("rb", stack_a, stack_b);
}

void	rot(int *stack_a, int *stack_b, int index)
{
	int a_steps;
	int	b_steps;

	a_steps = get_a_steps(stack_a, stack_b[index]);
	b_steps = index;
	if ((a_steps <= stack_a[0] / 2) && (index <= stack_b[0] / 2))
	{
		while (a_steps-- && b_steps--)
			print_command("rrr", stack_a, stack_b);
		while (a_steps-- >= 0)
			print_command("rra", stack_a, stack_b);
		while (b_steps-- > 0)
			print_command("rrb", stack_a, stack_b);
	}
	else if ((a_steps > stack_a[0] / 2) && (index > stack_b[0] / 2))
	{
		rr_rotation(stack_a, stack_b, a_steps, b_steps);
	}
	else
	{
		b_rot(stack_a, stack_b, b_steps);
		a_rot(stack_a, stack_b, a_steps);
	}
}
