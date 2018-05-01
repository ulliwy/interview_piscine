/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPriceV2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:39:19 by iprokofy          #+#    #+#             */
/*   Updated: 2018/05/01 14:10:43 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>

double getMax(int pizzaSize, double *prices, double *bestPrices)
{
	if (bestPrices[pizzaSize] != 0)
		return (bestPrices[pizzaSize]);
	for (int i = 1; i < pizzaSize; i++)
	{
		double itself = getMax(i, prices, bestPrices);
		double without = getMax(pizzaSize - i, prices, bestPrices);
		double best = itself + without;
		if (best < prices[pizzaSize])
			best = prices[pizzaSize];
		if (best > bestPrices[pizzaSize])
			bestPrices[pizzaSize] = best;
	}
	return bestPrices[pizzaSize];
}

double optimizedBestPrice(int pizzaSize, double *prices)
{
	double *bestPrices = malloc((pizzaSize + 1) * sizeof(double));
	memset(bestPrices, 0, pizzaSize + 1);
	bestPrices[1] = 1.5;
	return getMax(pizzaSize, prices, bestPrices);
}
