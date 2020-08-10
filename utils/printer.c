/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 13:52:43 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/03 13:55:52 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	printer(int *stack_a, int *stack_b, int steps)
{
	int	len;

	len = stack_a[0] > stack_b[0] ? stack_a[0] : stack_b[0];
	ft_printf("_________\n");
	while (len > 0)
	{
		if (len > 0 && len <= stack_a[0])
			ft_printf("%d", stack_a[len]);
		if (len > 0 && len <= stack_b[0])
			ft_printf("\t%d", stack_b[len]);
		ft_printf("\n");
		len--;
	}
	ft_printf("a%4d   b\n", steps);
}
