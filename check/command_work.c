/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_work.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:15:26 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/04 16:17:04 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#define COMMANDS "sa sb ss pa pb ra rb rr rra rrb rrr"

int	is_command(char *cmd, int eflag)
{
	int len;

	len = ft_strlen(cmd);
	if (!(ft_strchr(cmd, ' ')) && ft_strstr(COMMANDS, cmd)\
	&& len > 1 && len < 4)
		return (1);
	if (!eflag)
		ft_error("Error");
	else
		ft_printf("%s - not a command\n", cmd);
	return (0);
}

int	commander(char *cmd, int *stack_a, int *stack_b)
{
	if (ft_strequ(cmd, "sa"))
		sa(stack_a);
	else if (ft_strequ(cmd, "sb"))
		sb(stack_b);
	else if (ft_strequ(cmd, "ss"))
		ss(stack_a, stack_b);
	else if (ft_strequ(cmd, "pa"))
		pa(stack_a, stack_b);
	else if (ft_strequ(cmd, "pb"))
		pb(stack_a, stack_b);
	else if (ft_strequ(cmd, "ra"))
		ra(stack_a);
	else if (ft_strequ(cmd, "rb"))
		rb(stack_b);
	else if (ft_strequ(cmd, "rr"))
		rr(stack_a, stack_b);
	else if (ft_strequ(cmd, "rra"))
		rra(stack_a);
	else if (ft_strequ(cmd, "rrb"))
		rrb(stack_b);
	else if (ft_strequ(cmd, "rrr"))
		rrr(stack_a, stack_b);
	return (1);
}

int	multi_commands(char *cmd, int *stack_a, int *stack_b, int eflag)
{
	char	**cmds;
	int		steps;
	int		i;

	steps = 0;
	i = 0;
	if (ft_strstr(cmd, "  ") && !eflag)
		ft_error("Error");
	cmds = ft_strsplit(cmd, ' ');
	while (cmds[i])
	{
		if (is_command(cmds[i], eflag))
			steps += commander(cmds[i], stack_a, stack_b);
		free(cmds[i]);
		i++;
	}
	free(cmds);
	return (steps);
}

int	get_commands(int *stack_a, int *stack_b, t_pssp flags)
{
	char	*cmd;
	int		steps;

	steps = 0;
	while (((!sorted(stack_a, stack_b))\
	|| (sorted(stack_a, stack_b) && steps == 0))\
	&& get_next_line(0, &cmd))
	{
		if (!ft_strcmp(cmd, "end"))
			break ;
		steps += multi_commands(cmd, stack_a, stack_b, flags.e);
		if (flags.v)
			printer(stack_a, stack_b, steps);
		free(cmd);
	}
	return (steps);
}
