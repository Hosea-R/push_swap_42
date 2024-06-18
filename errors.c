/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:41:23 by mrazanad          #+#    #+#             */
/*   Updated: 2024/06/18 11:16:09 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}

static long	ft_atol(const char *nptr)
{
	long	i;
	long	signe;
	long	resultat;

	i = 0;
	signe = 1;
	resultat = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}
	while (nptr[i] == '+' || nptr[i] == '-')
	{
		if (!(nptr[i + 1] >= '0' && nptr[i + 1] <= '9'))
			return (0);
		if (nptr[i] == '-')
			signe *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		resultat = resultat * 10 + nptr[i] - '0';
		i++;
	}
	return (resultat * signe);
}

int	is_valid_number(const char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	contains_duplicates(char **arr, int len)
{
	int	*values;
	int	i;
	int	j;

	values = (int *)malloc(len * sizeof(int));
	if (!values)
		return (1);
	i = 0;
	while (i < len)
	{
		values[i] = ft_atoi(arr[i]);
		i++;
	}
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (values[i] == values[j])
			{
				free(values);
				return (1);
			}
			j++;
		}
		i++;
	}
	free(values);
	return (0);
}

int	is_int(const char *str)
{
	long	str_long;

	str_long = ft_atol(str);
	if (str_long >= -2147483648 && str_long <= 2147483647)
		return (1);
	return (0);
}
