/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_minmax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 12:47:26 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/04 12:54:10 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pssp.h"

int	find_min(int *stack, int index)
{
	int i;
	int min;
	int min_in;

	min = stack[1];
	min_in = 1;
	i = 2;
	while (i <= stack[0])
	{
		if (stack[i] < min)
		{
			min = stack[i];
			min_in = i;
		}
		i++;
	}
	return (index) ? min_in : min;
}

int	find_max(int *stack, int index)
{
	int i;
	int max;
	int max_in;

	max = stack[1];
	max_in = 1;
	i = 2;
	while (i <= stack[0])
	{
		if (stack[i] > max)
		{
			max = stack[i];
			max_in = i;
		}
		i++;
	}
	return (index) ? max_in : max;
}
