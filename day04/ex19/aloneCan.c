/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aloneCan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 21:44:45 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/04/30 21:52:29 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void aloneCan(int *arr, int n)
{
	int i = 0;
	int cane = 0;

	while (i < n)
	{
		cane = cane ^ arr[i];
		i++;
	}
	printf("%d\n", cane);
}