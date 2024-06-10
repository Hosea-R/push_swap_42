/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:02:35 by mrazanad          #+#    #+#             */
/*   Updated: 2024/06/10 10:54:18 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_input(int argc, char **argv)
{
	char	**split;

	split = NULL;
	if (argc == 2)
		split = ft_split(argv[1], ' ');
	else if (argc > 2)
	{
		split = malloc(sizeof(char *) * argc);
		if (!split)
			return (NULL);
		if (!copy_and_validate_args(argc, argv, split))
		{
			free_split(split);
			return (NULL);
		}
	}
	return (split);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
