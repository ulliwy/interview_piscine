/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 10:21:37 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/04/25 11:24:30 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

// struct s_player {
//   int   score;
//   char  *name;
// };

int getSize(struct s_player **players)
{
	int i = 0;

	while(players[i])
	{
		i++;
	}
	return i;
}

int part(struct s_player **players, int left, int right)
{
	struct s_player *temp;
	struct s_player *pi = players[right];
	int i = left - 1; //no lowest element yet
	int j = left;

	while (j < right)
	{
		if (players[j]->score <= pi->score)
		{
			i++;
			temp = players[i];
			players[i] = players[j];
			players[j] = temp;
		}
		j++;
	}
	temp = players[right];
	players[right] = players[i + 1];
	players[i + 1] = players[right];
	return (i + 1);
}

void sort(struct s_player **players, int left, int right)
{
	if (left < right)
	{
		int pi = part(players, left, right);
		sort(players, left, pi - 1);
		sort(players, pi, right);
	}
}

// implementing quick sort
void quickSort(struct s_player **players)
{
	sort(players, 0, getSize(players) - 1);
}
