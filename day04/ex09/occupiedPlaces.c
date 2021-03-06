/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occupiedPlaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 14:03:03 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/30 14:25:01 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int occupiedPlaces(unsigned int parkingRow)
{
	int i = 0;
	while (parkingRow)
	{
		parkingRow &= (parkingRow - 1);
		i++;
	}
	return i;
}
