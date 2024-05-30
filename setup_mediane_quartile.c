/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mediane_quartile.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:44:21 by mrazanad          #+#    #+#             */
/*   Updated: 2024/05/23 09:41:00 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mediane_quartile	*setup_mediane_quartile(int argc, char **argv)
{
	t_mediane_quartile	*mediane_quartile;
	char				**input;
	int					length;

	mediane_quartile = malloc(sizeof(t_mediane_quartile));
	if (!mediane_quartile)
		return (NULL);
	input = initialize_and_process_input(argc, argv, mediane_quartile);
	if (!input)
		return (NULL);
	length = count_strings(input);
	if (!configure_mq(mediane_quartile, input, length))
	{
		free_input(input, length);
		return (NULL);
	}
	free_input(input, length);
	return (mediane_quartile);
}
