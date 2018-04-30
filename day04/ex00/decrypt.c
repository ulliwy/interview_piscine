/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 10:11:43 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/30 10:40:21 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int toInt(char *bits)
{
	int result = 0;
	int i = 5;
	int shift = 1;

	while (i >= 0)
	{
		result = result + shift * (bits[i] - '0');
		shift = shift << 1;
		i--;
	}
	return result;
}

char *getSum(char *a, char *b)
{	
	int i = 5;
	int add = 0;

	while (i >= 0)
	{
		if (a[i] == '0' && b[i] == '0')
		{
			a[i] = add + '0';
			add = 0;
		}
		else if ((a[i] == '0' && b[i] == '1') || (a[i] == '1' && b[i] == '0'))
		{
			if (add)
			{
				a[i] = '0';
				add = 1;
			}
			else
			{
				a[i] = '1';
				add = 0;
			}
		}
		else
		{
			a[i] = add + '0';
			add = 1;
		}
		i--;
	}
	return a;
}