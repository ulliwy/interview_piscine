/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 09:54:48 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/04/25 14:44:46 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

// O(n*n)
void insertionSort(struct s_player **players)
{
	struct s_player *temp;
	int i = 1;
	int j;

	while (players[i])
	{
		temp = players[i];
		j = i - 1;
		while (j >= 0 && players[j]->score < temp->score)
		{
			players[j + 1] = players[j];
			j--;
		}
		players[j + 1] = temp;
		i++;
	}
}
