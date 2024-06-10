/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 09:41:40 by mrazanad          #+#    #+#             */
/*   Updated: 2024/06/10 08:56:17 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int copy_and_validate_args(int argc, char **argv, char **split)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (0);
		split[i - 1] = ft_strdup(argv[i]);
		if (!split[i - 1])
		{
			j = 0;
			while (j < i - 1)
			{
				free(split[j]);
				j++;
			}
			return (0);
		}
		i++;
	}
	split[argc - 1] = NULL;
	return (1);
}

char **create_result(char **split)
{
	int count;
	char **result;
	int i;

	count = 0;
	while (split[count])
		count++;
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
	{
		free_split(split);
		return (NULL);
	}
	i = 0;
	while (i < count)
	{
		result[i] = ft_strdup(split[i]);
		i++;
	}
	result[count] = NULL;
	free_split(split);
	return (result);
}

int count_strings(char **split)
{
	int count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}

int validate_arguments(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		if (!is_valid_number(split[i]) || !is_int(split[i]))
			return (0);
		i++;
	}
	return (1);
}

char **validate_and_split_input(int argc, char **argv)
{
	char **split;

	split = split_input(argc, argv);
	if (!split || contains_duplicates(split, count_strings(split)) || !validate_arguments(split))
	{
		free_split(split);
		return (NULL);
	}
	return (create_result(split));
}
