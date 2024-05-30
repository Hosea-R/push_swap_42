/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:44:59 by mrazanad          #+#    #+#             */
/*   Updated: 2024/05/23 09:42:44 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*new_node(int nbr, t_pile **element)
{
	(*element) = malloc(sizeof(t_pile));
	if (!(*element))
		return (NULL);
	(*element)->value = nbr;
	(*element)->next = NULL;
	(*element)->prev = NULL;
	return (*element);
}

int	add_to_stack(t_pile **stack, int nbr)
{
	t_pile	*node;

	if (new_node(nbr, &node) == NULL)
		return (-1);
	if ((*stack) == NULL)
	{
		(*stack) = node;
		(*stack)->next = *stack;
		(*stack)->prev = *stack;
	}
	else
	{
		node->prev = (*stack)->prev;
		node->next = (*stack);
		(*stack)->prev->next = node;
		(*stack)->prev = node;
		(*stack) = node;
	}
	return (1);
}

int	lentgh_stack(t_pile *stack)
{
	t_pile	*temp;
	int		i;

	if ((stack) && stack->next != stack)
	{
		temp = (stack)->next;
		i = 1;
		while (temp != (stack))
		{
			++i;
			temp = temp->next;
		}
		return (i);
	}
	return (0);
}
