/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPotentialCriminels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:47:11 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/04/26 09:05:14 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

// struct s_info {
// 	int gender;
// 	int height;
// 	int hairColor;
// 	int eyeColor;
// 	int glasses;
// 	int tattoo;
// 	int piercing;
// };

// struct s_criminal {
// 	char *name;
// 	int  description;
// };

int getDescription(struct s_info *info)
{
	if (!info)
		return 0;
	return info->gender * 1000000 +
		info->height * 100000 +
		info->hairColor * 10000 +
		info->eyeColor * 1000 +
		info->glasses * 100 +
		info->tattoo * 10 +
		info->piercing * 1;
}

void countSort(struct s_criminal **criminals, int ten, int n)
{
	struct s_criminal *result[n];
	int count[10] = {0};
	int i = 0;

	for (int i = 0; i < n; i++)
	{
		int digit = (criminals[i]->description / ten) % 10;
		count[digit]++;
	}
	
	i = 1;
	while (i < 10)
	{
		count[i] += count[i - 1];
		i++;
	}
	for (i = n - 1; i >= 0; i--)
	{
		int d = (criminals[i]->description / ten) % 10;

		result[count[d] - 1] = criminals[i]; // index is incremented by 1
		count[d]--;
	}

	for (i = 0; i < n; i++)
		criminals[i] = result[i];
}

int getMax(struct s_criminal **criminals, int *len)
{
	int max = 0;
	int i = 0;

	while (criminals[i])
	{
		if (criminals[i]->description > max)
			max = criminals[i]->description;
		i++;
	}
	*len = i;
	return max;
}

void sortCriminals(struct s_criminal **criminals)
{
	int len;
	int max = getMax(criminals, &len);

	for (int i = 1; max / i > 0; i *= 10)
		countSort(criminals, i, len);
}

int binarySearch(struct s_criminal **criminals, int low, int high, int desc)
{
	int i;
	int count = high - low;
	int step;

	while (count>0)
	{
		i = low;
		step = count / 2;
		i += step;
		if (criminals[i]->description < desc)
		{
			low = ++i;
			count -= step + 1;
		}
		else
			count = step;
	}
	if (low == high)
		return -1;
	return low;
}

struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info)
{
	int len;
	int upper;
	int desc = getDescription(info);
	int found;
	int i;
	struct s_criminal **result;

	getMax(criminals, &len);
	found = binarySearch(criminals, 0, len, desc);
	if (found == -1)
		return NULL;
	upper = found + 1;
	while (criminals[upper] && criminals[upper]->description == desc)
		upper++;
	result = malloc(sizeof(struct s_criminal *) * (upper - found + 1));
	i = 0;
	while (found != upper)
		result[i++] = criminals[found++];
	result[i] = NULL;
	return result;
}

