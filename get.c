/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:42:03 by mrazanad          #+#    #+#             */
/*   Updated: 2024/05/17 15:09:31 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_pile *stack, int elem)
{
	t_pile	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (tmp->next != stack)
	{
		if (tmp->value == elem)
			return (i);
		tmp = tmp->next;
		++i;
	}
	return (i);
}

int	get_min(t_pile *stack)
{
	int		min;
	t_pile	*tmp;

	tmp = stack->next;
	min = stack->value;
	while (tmp != stack && tmp != NULL)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	get_max(t_pile *stack)
{
	int		max;
	t_pile	*tmp;

	tmp = stack->next;
	max = stack->value;
	while (tmp != stack && tmp != NULL)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	get_correct_position(t_pile *stack, int elem)
{
	int		min;
	int		i;
	int		l;
	t_pile	*tmp;

	min = get_min(stack);
	if (elem > get_max(stack) || elem < min)
		return (get_index(stack, min));
	l = lentgh_stack(stack);
	i = -1;
	tmp = stack;
	while (++i < l)
	{
		if (tmp->prev->value < elem && elem < tmp->value)
			return (i);
		tmp = tmp->next;
	}
	return (0);
}
