/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:47:04 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/25 20:31:38 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

void countSort(unsigned char *utensils, int n)
{
	unsigned char *result = malloc(n);
	int i = 0;
	int count[16] = {0};

	while (i < n)
	{
		count[utensils[i]]++;
		i++;
	}
	i = 1;
	while (i < 16)
	{
		count[i] += count[i - 1];
		i++;
	}
	for (i = 0; i < n; i++)
	{
		result[count[utensils[i]] - 1] = utensils[i]; // index is incremented by 1
		count[utensils[i]]--;
	}
	for (i = 0; i < n; i++)
		utensils[i] = result[i];
	free(result);
}