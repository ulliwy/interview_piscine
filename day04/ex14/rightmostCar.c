/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rightmostCar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:55:52 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/30 16:57:24 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int rightmostCar(unsigned int parkingRow)
{
	int i = -1;
	while (parkingRow)
	{
		i++;
		if (parkingRow & 0x1)
			return i;
		parkingRow = parkingRow >> 1;
	}
	return -1;
}