/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:43:10 by mrazanad          #+#    #+#             */
/*   Updated: 2024/05/27 17:31:47 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	opti_moves(t_pile **stack_a, t_pile **stack_b, int pos_a, int pos_b)
{
	int	i;
	int	length_a;
	int	length_b;

	i = 0;
	length_a = lentgh_stack(*stack_a);
	length_b = lentgh_stack(*stack_b);
	if ((pos_a <= (length_a / 2)) && (pos_b <= (length_b / 2)))
	{
		while (i <= pos_a - 1 && i <= pos_b - 1)
		{
			rr(stack_a, stack_b);
			i++;
		}
	}
	if ((pos_a > (length_a / 2)) && (pos_b > (length_b / 2)))
	{
		while (i < (length_a - pos_a) && i < (length_b - pos_b))
		{
			rrr(stack_a, stack_b);
			i++;
		}
	}
	return (i);
}

static t_pile	*rr_rra(t_pile *stack_a, int pos_a, int i)
{
	if (pos_a <= (lentgh_stack(stack_a) / 2))
	{
		while (i <= pos_a - 1)
		{
			ra(&stack_a, 1);
			++i;
		}
	}
	else
	{
		while (i < (lentgh_stack(stack_a) - pos_a))
		{
			rra(&stack_a, 1);
			++i;
		}
	}
	return (stack_a);
}

void	insertion_sort(t_pile **p_a, t_pile **p_b, int b_move,
		t_mediane_quartile **mediane_quartile)
{
	int	pos_a;
	int	pos_b;
	int	i;

	pos_a = get_correct_position((*p_a), b_move);
	pos_b = get_index((*p_b), b_move);
	i = opti_moves(p_a, p_b, pos_a, pos_b);
	while ((*p_b)->value != b_move)
	{
		if (pos_b <= (lentgh_stack((*p_b)) / 2))
			rb(p_b, 1);
		else
			rrb(p_b, 1);
	}
	(*p_a) = rr_rra((*p_a), pos_a, i);
	pa(p_a, p_b, mediane_quartile);
}

void	optimize_push_a(t_pile *stack_a, t_pile *stack_b,
		t_mediane_quartile *mediane_quartile)
{
	mediane_quartile->length -= 3;
	while (mediane_quartile->length)
	{
		insertion_sort(&stack_a, &stack_b, get_best_move(stack_a, stack_b),
			&mediane_quartile);
		mediane_quartile->length--;
	}
	retrie_stack(&stack_a);
	stack_b = NULL;
	free_all(&stack_a, &stack_b, &mediane_quartile);
	exit(1);
}

void	optimize_push_b(t_pile *stack_a, t_pile *stack_b,
		t_mediane_quartile *mediane_quartile)
{
	while (inter_quartile(stack_a, mediane_quartile->quartile1,
			mediane_quartile->quartile2) && mediane_quartile->length >= 8)
	{
		if (stack_a->value >= mediane_quartile->quartile1
			&& stack_a->value <= mediane_quartile->mediane)
		{
			pb(&stack_a, &stack_b, &mediane_quartile);
			rb(&stack_b, 1);
			continue ;
		}
		if (stack_a->value <= mediane_quartile->quartile2
			&& stack_a->value >= mediane_quartile->mediane)
			pb(&stack_a, &stack_b, &mediane_quartile);
		else
			ra(&stack_a, 1);
	}
	while (lentgh_stack(stack_a) > 3)
	{
		pb(&stack_a, &stack_b, &mediane_quartile);
		if (stack_b->value < mediane_quartile->mediane)
			rb(&stack_b, 1);
	}
	if (!(already_sorted(stack_a)))
		sort_three(&stack_a);
	optimize_push_a(stack_a, stack_b, mediane_quartile);
}
