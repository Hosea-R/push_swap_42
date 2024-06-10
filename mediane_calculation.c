/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:42:56 by mrazanad          #+#    #+#             */
/*   Updated: 2024/06/10 11:10:52 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void put_mq(t_mediane_quartile **mediane_quartile, int length, int array[])
{
	(*mediane_quartile)->length = length;
	if (length % 2 == 0)
		(*mediane_quartile)->mediane = length / 2;
	else
		(*mediane_quartile)->mediane = (length + 1) / 2;
	(*mediane_quartile)->quartile1 = ((*mediane_quartile)->mediane + 1) / 2;
	if (length > 5)
	{
		if ((*mediane_quartile)->quartile1 < length)
			(*mediane_quartile)->quartile1 = array[(*mediane_quartile)->quartile1];
		else
			(*mediane_quartile)->quartile1 = 0;
		int quartile2_index = (*mediane_quartile)->mediane + (*mediane_quartile)->quartile1;
		if (quartile2_index < length)
			(*mediane_quartile)->quartile2 = array[quartile2_index];
		else
			(*mediane_quartile)->quartile2 = 0;
	}
	else
	{
		(*mediane_quartile)->quartile1 = 0;
		(*mediane_quartile)->quartile2 = 0;
	}
}
