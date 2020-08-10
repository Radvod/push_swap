/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:59:49 by hgalazza          #+#    #+#             */
/*   Updated: 2020/07/29 13:59:49 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	sorted(int *stack_a, int *stack_b)
{
	int i;

	i = stack_a[0];
	if (stack_b[0] != 0)
		return (0);
	while (i > 1)
	{
		if (stack_a[i] >= stack_a[i - 1])
			return (0);
		i--;
	}
	return (1);
}
