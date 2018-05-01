/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longestSequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 20:22:32 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/04/30 20:32:21 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int longestSequence(unsigned int parkingRow)
{
	int i = 0;
	int max = 0;

	while (parkingRow)
	{
		if (parkingRow & 1)
			i++;
		else if (i > max)
		{
			max = i;
			i = 0;
		}
		else
			i = 0;
		parkingRow >>= 1;
	}
	return i > max ? i : max;
}