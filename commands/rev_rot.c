/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:37:43 by hgalazza          #+#    #+#             */
/*   Updated: 2020/07/29 13:37:49 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	rra(int *stack_a)
{
	int last;
	int i;

	if (stack_a[0] > 1)
	{
		last = stack_a[1];
		i = 2;
		while (i <= stack_a[0])
		{
			stack_a[i - 1] = stack_a[i];
			i++;
		}
		stack_a[stack_a[0]] = last;
	}
}

void	rrb(int *stack_b)
{
	rra(stack_b);
}

void	rrr(int *stack_a, int *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
