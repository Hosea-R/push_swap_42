/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:40:14 by mrazanad          #+#    #+#             */
/*   Updated: 2024/05/23 09:43:02 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_pile **stack)
{
	t_pile	*current;
	t_pile	*temp;

	if (*stack == NULL)
		return ;
	current = *stack;
	while (current->next != *stack)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(current);
	*stack = NULL;
}

void	free_mq(t_mediane_quartile **mediane_quartile)
{
	if (mediane_quartile && *mediane_quartile)
	{
		free(*mediane_quartile);
		*mediane_quartile = NULL;
	}
}

void	free_all(t_pile **stack_a, t_pile **stack_b,
		t_mediane_quartile **mediane_quartile)
{
	free_stack(stack_a);
	free_stack(stack_b);
	free_mq(mediane_quartile);
}
