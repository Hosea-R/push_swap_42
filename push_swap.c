/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:43:31 by mrazanad          #+#    #+#             */
/*   Updated: 2024/05/27 17:59:46 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	initialize_stack(t_pile **stack_a, t_pile **stack_b, char **in_stack)
{
	int	i;
	int	t;

	i = 0;
	*stack_a = NULL;
	*stack_b = NULL;
	if (!in_stack)
		return (-1);
	while (in_stack[i])
		i++;
	while (--i >= 0)
	{
		t = add_to_stack(stack_a, ft_atoi(in_stack[i]));
		if (t == -1)
			return (-1);
		free(in_stack[i]);
	}
	free(in_stack);
	return (1);
}

static int	length_split(char **in_stack)
{
	int	i;

	i = -1;
	if (!in_stack)
		return (-1);
	while (in_stack[++i])
		free(in_stack[i]);
	free(in_stack);
	return (i);
}

char	**treat_input(int argc, char **argv)
{
	int		i;
	char	**split;

	if (argc > 2)
	{
		i = 0;
		split = malloc(sizeof(char *) * argc);
		while (++i < argc)
		{
			if (length_split(ft_split(argv[i], ' ')) != 1 || !split)
			{
				i++;
				while (--i != 0 || split != NULL)
					free(split[i]);
				free(split);
				return (NULL);
			}
			split[i - 1] = ft_strdup(argv[i]);
		}
		split[argc - 1] = NULL;
		return (split);
	}
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	return (NULL);
}

void	launch(t_pile *stack_a, t_pile *stack_b,
		t_mediane_quartile *mediane_quartile)
{
	if (mediane_quartile->length == 2)
		if (stack_a->value > stack_a->next->value)
			write(1, "sa\n", 3);
	if (mediane_quartile->length > 2)
		if (!already_sorted(stack_a))
			optimize_push_b(stack_a, stack_b, mediane_quartile);
	free_all(&stack_a, &stack_b, &mediane_quartile);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_mediane_quartile	*mediane_quartile;
	char				**input_data;

	if (argc == 1)
		exit(1);
	input_data = validate_and_split_input(argc, argv);
	if (!input_data)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	free_split(input_data);
	mediane_quartile = setup_mediane_quartile(argc, argv);
	if (!mediane_quartile)
	{
		free_split(input_data);
		write(2, "Error\n", 6);
		return (1);
	}
	if (initialize_and_launch_stacks(argc, argv, mediane_quartile))
	{
		free_resources(mediane_quartile);
		write(2, "Error\n", 6);
		return (1);
	}
}
