/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:21:19 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/03 13:42:41 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	usage(void)
{
	ft_printf("usage:./push_swap -u -e [5 4 3 2 ...]\n");
	ft_printf("usage:./checker -u -e -v [5 4 3 2 ...]\n");
	exit(1);
}

int		flags_w(char **argv, t_pssp *flags)
{
	int i;

	i = 1;
	ft_memset(flags, 0, sizeof(t_pssp));
	while (argv[i][0] == '-' && !ft_isdigit(argv[i][1]))
	{
		if (ft_strequ(argv[i], "-e"))
			flags->e = 1;
		else if (ft_strequ(argv[i], "-v"))
			flags->v = 1;
		else if (ft_strequ(argv[i], "-u"))
			usage();
		else
			ft_error("Error");
		if (!argv[++i])
			break ;
	}
	return (i);
}
