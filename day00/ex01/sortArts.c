/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:38:41 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/24 10:07:55 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int getSize(struct s_art **arts)
{
	int i = 0;

	while(arts[i])
	{
		i++;
	}
	return i;
}

int part(struct s_art **arts, int low, int high)
{
	char *pivot = arts[high]->name;
	struct s_art *tmp;
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (strcmp(arts[j]->name, pivot) <= 0)	
		{
			i++;
			tmp = arts[i];
			arts[i] = arts[j];
			arts[j] = tmp;
		}
	}
	tmp = arts[high];
	arts[high] = arts[i + 1];
	arts[i + 1] = tmp;
	return (i + 1);
}

void quickSort(struct s_art **arts, int low, int high)
{
	if (low < high)
	{
		int pi = part(arts, low, high);
		quickSort(arts, low, pi - 1);
		quickSort(arts, pi, high);
	}
}

// implementing quick sort
void sortArts(struct s_art **arts)
{
	quickSort(arts, 0, getSize(arts) - 1);
}