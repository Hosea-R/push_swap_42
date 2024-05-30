/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_launch_stack.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:42:23 by mrazanad          #+#    #+#             */
/*   Updated: 2024/05/27 17:44:05 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize_and_launch_stacks(int argc, char **argv,
		t_mediane_quartile *mediane_quartile)
{
	t_pile	*stack_a;
	t_pile	*stack_b;
	char	**input;

	stack_a = NULL;
	stack_b = NULL;
	input = treat_input(argc, argv);
	if (initialize_stack(&stack_a, &stack_b, input) == 1)
	{
		launch(stack_a, stack_b, mediane_quartile);
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (0);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (1);
}
