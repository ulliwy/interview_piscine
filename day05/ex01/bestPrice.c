/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 11:10:53 by iprokofy          #+#    #+#             */
/*   Updated: 2018/05/01 12:36:51 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void getMax(int pizzaSize, double *prices, double *max, double temp)
{
	if (pizzaSize == 0)
	{
		if (temp > *max)
			*max = temp;
	}
	for (int i = 1; i <= pizzaSize; i++)
		getMax(pizzaSize - i, prices, max, temp + prices[i]);
	return;
}

double bestPrice(int pizzaSize, double *prices)
{
	double max = 0;
	double temp = 0;
	getMax(pizzaSize, prices, &max, temp);
	return max;
}