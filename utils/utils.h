/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:14:02 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/05 14:47:25 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"
# define MAX(A, B) (A > B ? A : B)
# define MIN(A, B) (A > B ? B : A)

typedef struct
{
	int			e;
	int			v;
}				t_pssp;

void			ft_error(char *str);
int				sorted(int *stack_a, int *stack_b);
int				flags_w(char **argv, t_pssp *flags);
long			ft_atoi_long(char *s);
void			printer(int *stack_a, int *stack_b, int steps);

#endif
