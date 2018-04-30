/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftmostCar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:52:14 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/30 16:54:04 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int leftmostCar(unsigned int parkingRow)
{
	int i = -1;

	while (parkingRow)
	{
		i++;
		parkingRow = parkingRow >> 1;
	}
	return i;
}