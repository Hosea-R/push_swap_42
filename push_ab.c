/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:43:21 by mrazanad          #+#    #+#             */
/*   Updated: 2024/05/27 17:28:39 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_pile **stack_a, t_pile **stack_b,
		t_mediane_quartile **mediane_quartile)
{
	t_pile	*temp;

	if (add_to_stack(stack_a, (*stack_b)->value) == -1)
	{
		free_all(stack_a, stack_b, mediane_quartile);
		exit(1);
	}
	temp = (*stack_b);
	(*stack_b)->prev->next = (*stack_b)->next;
	(*stack_b)->next->prev = (*stack_b)->prev;
	(*stack_b) = (*stack_b)->next;
	free(temp);
	write(1, "pa\n", 3);
}

void	pb(t_pile **stack_a, t_pile **stack_b,
		t_mediane_quartile **mediane_quartile)
{
	t_pile	*temp;

	if (add_to_stack(stack_b, (*stack_a)->value) == -1)
	{
		free_all(stack_a, stack_b, mediane_quartile);
		exit(1);
	}
	temp = (*stack_a);
	(*stack_a)->prev->next = (*stack_a)->next;
	(*stack_a)->next->prev = (*stack_a)->prev;
	(*stack_a) = (*stack_a)->next;
	free(temp);
	write(1, "pb\n", 3);
}
