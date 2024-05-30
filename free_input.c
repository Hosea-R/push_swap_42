/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazanad <mrazanad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:40:27 by mrazanad          #+#    #+#             */
/*   Updated: 2024/05/23 10:40:15 by mrazanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_input(char **input, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		free(input[i]);
		i++;
	}
	free(input);
}
