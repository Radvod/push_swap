/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:12:15 by hgalazza          #+#    #+#             */
/*   Updated: 2020/07/29 13:14:10 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	pa(int *stack_a, int *stack_b)
{
	if (stack_b[0] > 0)
		stack_a[++stack_a[0]] = stack_b[stack_b[0]--];
}

void	pb(int *stack_a, int *stack_b)
{
	pa(stack_b, stack_a);
}

void	pp(int *stack_a, int *stack_b)
{
	pa(stack_a, stack_b);
	pb(stack_a, stack_b);
}
