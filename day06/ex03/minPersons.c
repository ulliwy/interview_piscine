/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minPersons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:19:10 by iprokofy          #+#    #+#             */
/*   Updated: 2018/05/02 22:18:55 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int minPersons(int elements, int minPercentage)
{
	long double p;
	int n = 2;
	while (1)
	{
		p = 1;
		for (int i = 1; i < n; i++)
		{
			p = p * (1 - (long double)i / (long double)elements);
		}
		p = 1 - p;
		if (p * 100 > minPercentage)
			return n;
		else
			n++;
	}
	return n;
}
