/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aloneCans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 21:55:17 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/04/30 22:34:42 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void aloneCans(int *arr, int n)
{
	int xor = 0;
	int v1 = 0;
	int v2 = 0;
	int i = 0;
	while (i < n)
	{
		xor = xor ^ arr[i];
		i++;
	}
	xor = xor & ~(xor - 1); // right most significant
	i = 0;
	while (i < n)
	{
		if (arr[i] & xor)
			v1 = v1 ^ arr[i];
		else
			v2 = v2 ^ arr[i];
		i++;
	}
	printf("%d\n", v1);
	printf("%d\n", v2);

}