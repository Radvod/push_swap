/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:28:56 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/03 13:57:30 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../init_stacks/init_stacks.h"
# include "../commands/commands.h"
# include "../utils/utils.h"

int	commander(char *cmd, int *stack_a, int *stack_b);
int	get_commands(int *stack_a, int *stack_b, t_pssp	flags);

#endif
