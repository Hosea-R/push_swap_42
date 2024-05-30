/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:44:39 by mrazanad          #+#    #+#             */
/*   Updated: 2024/05/21 15:21:45 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_pile **stack_a)
{
	int	temp;

	temp = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = temp;
	write(1, "sa\n", 3);
}

void	sb(t_pile **stack_b)
{
	int	temp;

	temp = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = temp;
	write(1, "sb\n", 3);
}

void	ss(t_pile **a, t_pile **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
