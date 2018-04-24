/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 11:45:34 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/23 12:13:07 by iprokofy         ###   ########.fr       */
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

int binarySearch(struct s_art **arts, int low, int high, char *name)
{
	int mid;

	if (low < high)
	{
		mid = (high - low) / 2 + low;
		if (strcmp(arts[mid]->name, name) == 0)
			return (arts[mid]->price);
		if (strcmp(arts[mid]->name, name) > 0)
			return (binarySearch(arts, low, mid - 1, name));
		if (strcmp(arts[mid]->name, name) < 0)
			return (binarySearch(arts, mid + 1, high, name));
	}
	return (-1);
}

// implementing binarySearch
int searchPrice(struct s_art **arts, int n, char *name)
{
	return (binarySearch(arts, 0, n - 1, name));
}