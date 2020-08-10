/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_sorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 13:06:58 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/05 14:38:46 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pssp.h"

int	a_sort(int *stack_a)
{
	int i;
	int i_min;

	i = stack_a[0];
	i_min = find_min(stack_a, 1);
	while (i > i_min + 1)
	{
		if (stack_a[i] > stack_a[i - 1])
			return (0);
		i--;
	}
	i--;
	while (i > 1)
	{
		if (stack_a[i] > stack_a[i - 1])
			return (0);
		i--;
	}
	return (stack_a[stack_a[0]] > stack_a[1] || i_min == stack_a[0]);
}
