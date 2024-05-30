/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:44:03 by mrazanad          #+#    #+#             */
/*   Updated: 2024/05/17 09:44:04 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_pile **stack_a, int print)
{
	if (*stack_a && (*stack_a)->prev != *stack_a)
	{
		*stack_a = (*stack_a)->prev;
		if (print)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_pile **stack_b, int print)
{
	if (*stack_b && (*stack_b)->prev != *stack_b)
	{
		*stack_b = (*stack_b)->prev;
		if (print)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_pile **stack_a, t_pile **stack_b)
{
	if (*stack_a && (*stack_a)->prev != *stack_a && *stack_b
		&& (*stack_b)->prev != *stack_b)
	{
		rra(stack_a, 0);
		rrb(stack_b, 0);
		write(1, "rrr\n", 4);
	}
}
