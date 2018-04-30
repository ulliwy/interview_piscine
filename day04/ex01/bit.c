/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 10:41:46 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/30 11:36:31 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *getNot(char *a)
{
	int i = 5;
	while (i >= 1)
	{
		if (a[i] == '0')
			a[i] = '1';
		else
			a[i] = '0';
		i--;
	}
	return a;
}

char *getAnd(char *a, char *b)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int lim_i = 4;
	int lim_j = 4;

	if (a[i] == '~')
	{
		a = getNot(a);
		i++;
		lim_i = 5;
	}
	if (b[j] == '~')
	{
		b = getNot(b);
		j++;
		lim_j = 5;
	}

	while (i < lim_i && j < lim_j)
	{
		if (a[i] == '1' && b[j] == '1')
			a[k] = '1';
		else
			a[k] = '0';
		i++; j++; k++;
	}
	a[k] = '\0';
	return a;
}

char *getOr(char *a, char *b)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int lim_i = 4;
	int lim_j = 4;

	if (a[i] == '~')
	{
		a = getNot(a);
		i++;
		lim_i = 5;
	}
	if (b[j] == '~')
	{
		b = getNot(b);
		j++;
		lim_j = 5;
	}

	while (i < lim_i && j < lim_j)
	{
		if (a[i] == '1' || b[j] == '1')
			a[k] = '1';
		else
			a[k] = '0';
		i++; j++; k++;
	}
	a[k] = '\0';
	return a;
}

int toInt(char *bits)
{
	int result = 0;
	int i = 3;
	int shift = 1;

	while (i >= 0)
	{
		result = result + shift * (bits[i] - '0');
		shift = shift << 1;
		i--;
	}
	return result;
}
