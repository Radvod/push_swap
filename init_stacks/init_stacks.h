/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:18:06 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/05 14:33:29 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_STACKS_H
# define INIT_STACKS_H

# include "../libft/libft.h"
# include "../utils/utils.h"

int			is_num(char *s);
int			ft_stackfree(char **stc);
int			ft_stacklen(char **stc);
void		dup_check(int *stack, int eflag);
int			*init_a(int len, char **stack, int eflag);
int			*init_b(int len);
char		*get_valid(char *s);
char		*num_convert(char *s);
char		*ft_isinteger(char *nbr, int eflag);
char		*input_check(char *str, int eflag);

#endif
