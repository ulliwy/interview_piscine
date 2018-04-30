/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:39:05 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/30 15:43:22 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int carPosition(unsigned int parkingRow)
{
	int i = 0;
	int found = 0;

	while (parkingRow)
	{
		if (parkingRow & 0x1)
		{
			found++;
		}
		i++;
		parkingRow = parkingRow / 2;
	}
	if (!i || found != 1)
		return -1;
	return i - 1;
}
