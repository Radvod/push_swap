/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pssp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 11:47:28 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/05 13:19:18 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSSP_H
# define PSSP_H

# include "../check/checker.h"

void	print_command(char *cmd, int *stack_a, int *stack_b);
int		find_min(int *stack, int index);
int		find_max(int *stack, int index);
int		a_sort(int *stack_a);
int		push_from_b(int *stack_a, int *stack_b);
void	work_b(int *stack_a, int *stack_b);
int		get_best_index(int *stack_a, int *stack_b);
void	rot(int *stack_a, int *stack_b, int index);
void	stack_sort(int *stack_a, int *stack_b);

#endif
