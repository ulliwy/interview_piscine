/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piano.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 20:37:17 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/04/30 21:06:20 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

int **pianoDecompress(struct s_bit *bit, int l)
{
	int num;
	int j;

	int **arr = calloc(1, sizeof(int *) * bit->n);
	for (int i = 0; i < bit->n; i++)
	{
		arr[i] = calloc(1, sizeof(int) * l);
		num = bit->arr[i];
		j = 0;
		while (num)
		{
			j++;
			num = num >> 1;
		}
		arr[i][j] = 1;
	}
	return arr;
}