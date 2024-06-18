/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:42:56 by mrazanad          #+#    #+#             */
/*   Updated: 2024/06/18 11:08:37 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_mq(t_mediane_quartile **med_quar, int length, int array[])
{
	int	quartile1_index;
	int	quartile2_index;

	if (!med_quar || !*med_quar || !array)
		return ;
	if (length % 2 == 0)
		(*med_quar)->mediane = array[length / 2 - 1];
	else
		(*med_quar)->mediane = array[length / 2];
	quartile1_index = length / 4;
	quartile2_index = (3 * length) / 4;
	if (length >= 4)
	{
		(*med_quar)->quartile1 = array[quartile1_index];
		(*med_quar)->quartile2 = array[quartile2_index];
	}
	else
	{
		(*med_quar)->quartile1 = 0;
		(*med_quar)->quartile2 = 0;
	}
	(*med_quar)->length = length;
}
