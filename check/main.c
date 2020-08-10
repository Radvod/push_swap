/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:34:10 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/03 13:57:30 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	int		i;
	int		steps;
	t_pssp	flags;

	if (argc < 2)
		exit(1);
	i = flags_w(argv, &flags);
	if (!*(argv += i))
		exit(1);
	stack_a = init_a(argc - i, argv, flags.e);
	stack_b = init_b(stack_a[0] + 1);
	if (flags.v)
		printer(stack_a, stack_b, 0);
	steps = get_commands(stack_a, stack_b, flags);
	if (sorted(stack_a, stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_printf("Steps: %d\n", steps);
	free(stack_a);
	free(stack_b);
	return (0);
}
