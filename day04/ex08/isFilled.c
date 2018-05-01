/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isFilled.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 13:49:42 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/30 20:19:41 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int isFilled(unsigned int parkingRow)
{
	return parkingRow && (parkingRow & (-(~parkingRow))) == 0; // i & (i + 1)
}
