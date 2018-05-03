/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probaDistance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 10:21:28 by iprokofy          #+#    #+#             */
/*   Updated: 2018/05/02 10:32:35 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double probaDistance(int dist, int *locations, int n)
{
	double all = 0;
	double greater = 0;
	double prob;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			all++;
			if (locations[i] - locations[j] > dist || locations[j] - locations[i] > dist)
				greater++;
		}
	}
	prob = greater / all;
	return prob;
}
