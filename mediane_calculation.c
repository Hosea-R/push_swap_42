/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:42:56 by mrazanad          #+#    #+#             */
/*   Updated: 2024/06/10 08:15:44 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_mq(t_mediane_quartile **mediane_q, int length, int array[])
{
	int	quartile2_index;

	quartile2_index = (*mediane_q)->mediane + (*mediane_q)->quartile1;
	(*mediane_q)->length = length;
	if (length % 2 == 0)
		(*mediane_q)->mediane = length / 2;
	else
		(*mediane_q)->mediane = (length + 1) / 2;
	(*mediane_q)->quartile1 = ((*mediane_q)->mediane + 1) / 2;
	(*mediane_q)->quartile1 = 0;
	(*mediane_q)->quartile2 = 0;
	if (length > 5)
	{
		if ((*mediane_q)->quartile1 < length)
			(*mediane_q)->quartile1 = array[(*mediane_q)->quartile1];
		else
			(*mediane_q)->quartile1 = 0;
		if (quartile2_index < length)
			(*mediane_q)->quartile2 = array[quartile2_index];
		else
			(*mediane_q)->quartile2 = 0;
	}
}
