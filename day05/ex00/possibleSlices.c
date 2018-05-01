/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 10:28:37 by iprokofy          #+#    #+#             */
/*   Updated: 2018/05/01 11:08:37 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void getSizes(struct s_array *arr, int pizzaSize)
{
	struct s_array *arr2;
	if (pizzaSize == 0)
	{
		if (arr->sum != 0)
			arrayPrint(arr);
		return;
	}
	for (int i = 1; i <= pizzaSize; i++)
	{
		arr2 = arrayClone(arr);
		arrayAppend(arr2, i);
		getSizes(arr2, pizzaSize - i);
	}
}

void printPossibleSlices(int pizzaSize)
{
	struct s_array *arr = arrayInit();
	getSizes(arr, pizzaSize);
}