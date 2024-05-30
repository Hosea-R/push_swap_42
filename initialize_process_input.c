/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_process_input.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:42:38 by mrazanad          #+#    #+#             */
/*   Updated: 2024/05/27 18:00:38 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**initialize_and_process_input(int argc, char **argv,
		t_mediane_quartile *mediane_quartile)
{
	char	**input;

	input = treat_input(argc, argv);
	if (!input)
	{
		write(2, "Error\n", 6);
		free(mediane_quartile);
		return (NULL);
	}
	return (input);
}
