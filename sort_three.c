/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:44:31 by mrazanad          #+#    #+#             */
/*   Updated: 2024/05/23 10:08:45 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_pile **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->prev->value;
	if ((first < second) && (second > third) && (first < third))
	{
		rra(stack_a, 1);
		sa(stack_a);
	}
	else if ((first < second) && (second > third) && (first > third))
		rra(stack_a, 1);
	else if ((first > second) && (second < third) && (first > third))
		ra(stack_a, 1);
	else if ((first > second) && (second > third))
	{
		sa(stack_a);
		rra(stack_a, 1);
	}
	else
		sa(stack_a);
}
