/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   er_wrk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgalazza <hgalazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 12:41:12 by hgalazza          #+#    #+#             */
/*   Updated: 2020/08/03 16:30:16 by hgalazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_stacks.h"
#define INT_MAX 2147483647
#define INT_MIN -2147483648

int		is_num(char *s)
{
	int min;

	min = 0;
	if (*s == '-')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
		min++;
	}
	if (!min)
		exit(1);
	return (1);
}

char	*get_valid(char *s)
{
	char *new;

	ft_printf("Invalid input %s\n", s);
	ft_printf("Input valid or skip:\t");
	while (get_next_line(0, &new))
	{
		if (is_num(new))
			return (new);
		if (ft_isinteger(new, 1))
			return (new);
		if (ft_strequ(new, "skip"))
		{
			free(new);
			return (NULL);
		}
		ft_printf("%s - invalid\n", new);
		ft_printf("Input valid or skip:\t");
		free(new);
	}
	return (NULL);
}

char	*num_convert(char *s)
{
	if (!ft_strcmp(s, "zero"))
		return ("0");
	else if (!ft_strcmp(s, "one"))
		return ("1");
	else if (!ft_strcmp(s, "two"))
		return ("2");
	else if (!ft_strcmp(s, "three"))
		return ("3");
	else if (!ft_strcmp(s, "four"))
		return ("4");
	else if (!ft_strcmp(s, "five"))
		return ("5");
	else if (!ft_strcmp(s, "six"))
		return ("6");
	else if (!ft_strcmp(s, "seven"))
		return ("7");
	else if (!ft_strcmp(s, "eight"))
		return ("8");
	else if (!ft_strcmp(s, "nine"))
		return ("9");
	else if (!ft_strcmp(s, "ten"))
		return ("10");
	else
		return (get_valid(s));
}

char	*ft_isinteger(char *nbr, int eflag)
{
	long num;

	if ((!nbr || ft_strlen(nbr) > 11) && !eflag)
		return (NULL);
	else if (ft_strlen(nbr) > 11 && eflag)
		nbr = get_valid(nbr);
	num = ft_atoi_long(nbr);
	if (num <= (long)INT_MAX && num >= (long)INT_MIN)
		return (nbr);
	else
		return (NULL);
}

char	*input_check(char *str, int eflag)
{
	char *ret;

	ret = str;
	if (!(is_num(str)))
	{
		if (!eflag)
			ft_error("Error");
		if (!(ret = num_convert(str)))
			return (NULL);
	}
	if (!(ret = ft_isinteger(ret, eflag)))
	{
		if (!eflag)
			ft_error("Error");
		ft_error("Some arguments are bigger than an integer");
	}
	return (ret);
}
