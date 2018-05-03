/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roulette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:55:05 by iprokofy          #+#    #+#             */
/*   Updated: 2018/05/03 10:20:17 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

double probabilityWin(double initDollars, double wantedDollars, int nbGame)
{
	if (initDollars >= wantedDollars)
		return 1;
	if (!nbGame || !initDollars)
		return 0;
	double red = 18.0 / 37.0 * probabilityWin(2 * initDollars, wantedDollars, nbGame - 1);
	double green = 1.0 / 37.0 * probabilityWin(initDollars / 2.0, wantedDollars, nbGame - 1);
	return red + green;
}
