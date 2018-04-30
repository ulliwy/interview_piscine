/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 13:12:12 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/30 13:20:56 by iprokofy         ###   ########.fr       */
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

char *getXor(char *a, char *b)
{
	int i = 0;

	while (i < 6)
	{
		if (a[i] == b[i])
			a[i] = '0';
		else
			a[i] = '1';
		i++;
	}
	return a;
}
