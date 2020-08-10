/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:02:04 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/05 14:33:29 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_stacks.h"

int		*is_split(char **stack, int eflag)
{
	char	**new;
	int		*arr;
	int		len;

	new = ft_strsplit(*stack, ' ');
	if (new[1] == NULL)
	{
		ft_stackfree(new);
		return (NULL);
	}
	len = ft_stacklen(new);
	arr = init_a(len, new, eflag);
	ft_stackfree(new);
	return (arr);
}

int		*init_a(int len, char **stack, int eflag)
{
	int		*arr;
	char	*tmp;
	int		i;

	if ((arr = is_split(stack, eflag)))
		return (arr);
	arr = (int *)malloc(sizeof(int) * (len + 1));
	arr[0] = len;
	i = 1;
	while (i <= arr[0])
	{
		if ((tmp = input_check(stack[--len], eflag)))
			arr[i++] = ft_atoi(tmp);
		else
			arr[0]--;
	}
	dup_check(arr, eflag);
	return (arr);
}

int		*init_b(int len)
{
	int *arr;

	arr = (int *)malloc(sizeof(int) * len);
	arr[0] = 0;
	return (arr);
}
