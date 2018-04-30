/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 11:38:10 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/30 13:03:37 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int toInt(char *bits)
{
	int result = 0;
	int i = 5;
	int shift = 1;
	int neg = (bits[0] == '1') ? 1 : 0;

	while (i >= 1)
	{
		result = result + shift * ((bits[i] == '1') ^ neg);
		shift = shift << 1;
		i--;
	}
	return neg ? -result -1 : result;
}

char *rightShift(char *bin, int k)
{
	int i = 5;

	if (k < 6)
	{
		while (i - k >= 0)
		{
			bin[i] = bin[i - k];
			i--;
		}
	}
	i = 0;
	while (i < k && i < 6)
	{
	 	bin[i] = '1';
		i++;
	}
	return bin;
}

char *leftShift(char *bin, int k)
{
	int i = 0;

	if (k < 6)
	{
		while (i + k < 6)
		{
			bin[i] = bin[i + k];
			i++;
		}
	}
	i = 5;
	while (i >= 0 && k > 0)
	{
	 	bin[i] = '0';
	 	i--;
	 	k--;
	}
	return bin;
}
