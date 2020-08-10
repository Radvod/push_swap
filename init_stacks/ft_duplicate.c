/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:29:19 by hgalazza          #+#    #+#             */
/*   Updated: 2020/07/29 17:39:40 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_stacks.h"

int		is_dup(int n, int *stack)
{
	int i;

	i = stack[0];
	while (i > 0)
	{
		if (stack[i] == n)
			return (1);
		i--;
	}
	return (0);
}

void	del_dup(int *stack, int num)
{
	while (++num <= stack[0])
		stack[num - 1] = stack[num];
	stack[0]--;
}

int		get_answ(void)
{
	char *answ;

	ft_printf("Your input contains duplicates\n");
	ft_printf("Would you like to del it (yes/no):\t");
	while (get_next_line(0, &answ))
	{
		if (!ft_strcmp(answ, "yes"))
		{
			free(answ);
			return (1);
		}
		else if (!ft_strcmp(answ, "no"))
		{
			ft_printf("ERROR - invalid input\n");
			free(answ);
			exit(1);
		}
		ft_printf("Would you like to del it (yes/no):\t");
		free(answ);
	}
	return (0);
}

void	dup_check(int *stack, int eflag)
{
	int	*new;
	int	i;
	int	answ;

	i = 1;
	answ = 0;
	new = init_b(stack[0] + 1);
	while (i <= stack[0])
	{
		if (is_dup(stack[i], new))
		{
			if (!eflag)
				ft_error("Error");
			if (!answ)
				answ = get_answ();
			del_dup(stack, i);
		}
		else
		{
			new[0]++;
			new[new[0]] = stack[i];
			i++;
		}
	}
	free(new);
}
