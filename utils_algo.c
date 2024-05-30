/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:44:51 by mrazanad          #+#    #+#             */
/*   Updated: 2024/05/23 09:48:09 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	enumerate_move(t_pile *stack_a, t_pile *stack_b, int element)
{
	int	enumerate;
	int	index;

	index = get_index(stack_b, element);
	enumerate = 1;
	if (index > 1 && index > (lentgh_stack(stack_b) / 2))
		enumerate += lentgh_stack(stack_b) - index - 1;
	else if (index > 1 && index <= (lentgh_stack(stack_b) / 2))
		enumerate += index - 1;
	index = get_correct_position(stack_a, element);
	if (index > 1 && index > (lentgh_stack(stack_a) / 2))
		enumerate += lentgh_stack(stack_a) - index - 1;
	else if (index > 1 && index <= (lentgh_stack(stack_a) / 2))
		enumerate += index - 1;
	return (enumerate);
}

int	get_best_move(t_pile *stack_a, t_pile *stack_b)
{
	int		best_move_node;
	int		move_enumerate;
	int		best_move_enumerate;
	t_pile	*temp;

	best_move_node = stack_b->value;
	best_move_enumerate = enumerate_move(stack_a, stack_b, best_move_node);
	temp = stack_b->next;
	while (temp != stack_b && temp != NULL)
	{
		move_enumerate = enumerate_move(stack_a, stack_b, temp->value);
		if (move_enumerate < best_move_enumerate)
		{
			best_move_enumerate = move_enumerate;
			best_move_node = temp->value;
		}
		temp = temp->next;
	}
	return (best_move_node);
}

int	already_sorted(t_pile *stack)
{
	int	i;
	int	length;

	length = lentgh_stack(stack);
	if (length > 0)
	{
		i = 1;
		while (i++ < length)
		{
			if (stack->value > stack->next->value)
				return (0);
			stack = stack->next;
		}
		return (1);
	}
	return (0);
}

int	inter_quartile(t_pile *stack, int quartile1, int quartile2)
{
	t_pile	*temp;
	int		length;
	int		i;

	length = lentgh_stack(stack);
	i = 0;
	temp = stack;
	while (i < length)
	{
		if (quartile1 <= temp->value && temp->value <= quartile2)
			return (1);
		temp = temp->next;
		++i;
	}
	return (0);
}

void	retrie_stack(t_pile **stack)
{
	int		min_value;
	int		index;
	t_pile	*stack_a;

	stack_a = *stack;
	min_value = get_min(stack_a);
	if (stack_a->value != min_value)
	{
		index = get_index(stack_a, min_value);
		if (index <= lentgh_stack(stack_a) / 2)
			while (stack_a->value != min_value)
				ra(&stack_a, 1);
		else
			while (stack_a->value != min_value)
				rra(&stack_a, 1);
	}
	(*stack) = stack_a;
}
