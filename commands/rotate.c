/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:23:27 by hgalazza          #+#    #+#             */
/*   Updated: 2020/07/29 13:23:49 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	ra(int *stack_a)
{
	int first;
	int i;

	if (stack_a[0] > 1)
	{
		first = stack_a[stack_a[0]];
		i = stack_a[0] - 1;
		while (i > 0)
		{
			stack_a[i + 1] = stack_a[i];
			i--;
		}
		stack_a[1] = first;
	}
}

void	rb(int *stack_b)
{
	ra(stack_b);
}

void	rr(int *stack_a, int *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
