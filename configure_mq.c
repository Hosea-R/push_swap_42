/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_mq.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:39:45 by mrazanad          #+#    #+#             */
/*   Updated: 2024/05/23 09:40:35 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	configure_mq(t_mediane_quartile *mediane_quartile,
		char **input, int length)
{
	int	*int_array;

	int_array = convert_to_int_array(input, length);
	if (!int_array)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	put_mq(&mediane_quartile, length, int_array);
	free(int_array);
	if (mediane_quartile->length == 0)
	{
		write(2, "Error\n", 6);
		free_mq(&mediane_quartile);
		return (0);
	}
	return (1);
}
