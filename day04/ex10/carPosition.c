/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 14:30:43 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/30 15:40:59 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		parkingRow = parkingRow >> 1;
	}
	if (!i || found != 1)
		return -1;
	return i - 1;
}
