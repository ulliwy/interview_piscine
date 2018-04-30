/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearBits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:45:51 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/30 15:53:12 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int clearBits(unsigned int parkingRow, int n)
{
	parkingRow = parkingRow >> n;
	parkingRow = parkingRow << n;
	return parkingRow;
}