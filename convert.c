/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:39:59 by mrazanad          #+#    #+#             */
/*   Updated: 2024/05/17 09:57:42 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*convert_to_int_array(char **input, int length)
{
	int	*array;
	int	i;

	i = 0;
	array = malloc(sizeof(int) * length);
	if (!array)
		return (NULL);
	while (i < length)
	{
		array[i] = ft_atoi(input[i]);
		i++;
	}
	return (array);
}
