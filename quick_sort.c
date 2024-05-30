/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:43:45 by mrazanad          #+#    #+#             */
/*   Updated: 2024/05/23 09:40:35 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	spread_s_b(int array[], int small, int big)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[big];
	i = (small - 1);
	j = small;
	while (j < big)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
		j++;
	}
	swap(&array[i + 1], &array[big]);
	return (i + 1);
}

void	quick_sort(int array[], int small, int big)
{
	int	pivot;

	if (small < big)
	{
		pivot = spread_s_b(array, small, big);
		quick_sort(array, small, pivot - 1);
		quick_sort(array, pivot + 1, big);
	}
}

static void	find_duplicate(int array[], int length,
		t_mediane_quartile **mediane_quartile)
{
	int	i;
	int	temp;
	int	dup;

	i = 0;
	dup = 1;
	temp = array[0];
	while (++i < length)
	{
		if (array[i] == temp)
			dup = 0;
		temp = array[i];
	}
	(*mediane_quartile)->length = length;
	if (dup)
		(*mediane_quartile)->length = dup;
	(*mediane_quartile)->mediane = (length + 1) / 2;
	put_mq(mediane_quartile, length, array);
}

void	get_mediane_quartile(char **input,
		t_mediane_quartile **mediane_quartile, int *error)
{
	int	length;
	int	i;
	int	*tab;

	length = 0;
	while (input[length] && input != NULL)
		++length;
	tab = malloc(sizeof(int) * length);
	if (!tab || !input)
	{
		(*mediane_quartile) = NULL;
		return ;
	}
	i = length;
	while (--i != -1)
	{
		tab[i] = ft_atoi_and_check(input[i], error);
		free(input[i]);
	}
	free(input);
	quick_sort(tab, 0, length - 1);
	find_duplicate(tab, length, mediane_quartile);
	(*mediane_quartile)->mediane = tab[((*mediane_quartile)->mediane) - 1];
	free(tab);
}
