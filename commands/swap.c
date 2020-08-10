/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 12:51:01 by hgalazza          #+#    #+#             */
/*   Updated: 2020/07/29 12:53:00 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	sa(int *stack_a)
{
	int first;

	if (stack_a[0] > 1)
	{
		first = stack_a[stack_a[0]];
		stack_a[stack_a[0]] = stack_a[stack_a[0] - 1];
		stack_a[stack_a[0] - 1] = first;
	}
}

void	sb(int *stack_b)
{
	sa(stack_b);
}

void	ss(int *stack_a, int *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
