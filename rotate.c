/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:44:10 by mrazanad          #+#    #+#             */
/*   Updated: 2024/05/17 09:44:11 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_pile **stack_a, int print)
{
	if (*stack_a && (*stack_a)->next != *stack_a)
	{
		*stack_a = (*stack_a)->next;
		if (print)
			write(1, "ra\n", 3);
	}
}

void	rb(t_pile **stack_b, int print)
{
	if (*stack_b && (*stack_b)->next != *stack_b)
	{
		*stack_b = (*stack_b)->next;
		if (print)
			write(1, "rb\n", 3);
	}
}

void	rr(t_pile **stack_a, t_pile **stack_b)
{
	if (*stack_a && (*stack_a)->next != *stack_a && *stack_b
		&& (*stack_b)->next != *stack_b)
	{
		ra(stack_a, 0);
		rb(stack_b, 0);
		write(1, "rr\n", 3);
	}
}
