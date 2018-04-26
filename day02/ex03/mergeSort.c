/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:27:42 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/04/26 16:25:38 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int getSize(struct s_player **players)
{
	int i = 0;

	while(players[i])
	{
		i++;
	}
	return i;
}

void merge(struct s_player **players, int left, int mid, int right)
{
	int L = mid - left + 1;
	int R  = right - mid;
	int i, j, k;
	struct s_player *Larr[L];
	struct s_player *Rarr[R];

	for (i = 0; i < L; i++)
		Larr[i] = players[left + i];
	for (j = 0; j < R; j++)
		Rarr[j] = players[mid + 1 + j];

	i = j = 0;
	k = left;
	while (i < L && j < R)
	{
		if (Larr[i]->score >= Rarr[j]->score)
		{
			players[k] = Larr[i];
			i++;
		}
		else
		{
			players[k] = Rarr[j];
			j++;
		}
		k++;
	}
	while (i < L)
	{
		players[k] = Larr[i];
		i++;
		k++;
	}
	while (j < R)
	{
		players[k] = Rarr[j];
		j++;
		k++;
	}
}

void sort(struct s_player **players, int left, int right)
{
	int mid = left + (right - left) / 2;

	if (left < right)
	{
		sort(players, left, mid);
		sort(players, mid + 1, right);
		merge(players, left, mid, right);
	}
}

struct s_player **mergeSort(struct s_player **players)
{
	sort(players, 0, getSize(players) - 1);
	return players;
}