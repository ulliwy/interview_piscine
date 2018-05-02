/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeThemEat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:26:33 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/05/01 21:29:53 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

int recurse(struct s_people **people, int num, int nbTable, int totalTime, int *arr)
{
	int result = 0;
	int i = num;
	if (!people[num])
		return 1;
	for (int j = 0; j < nbTable; j++)
	{
		if (arr[j] + people[i]->time <= totalTime)
		{
			arr[j] += people[i]->time;
			result = recurse(people, num + 1, nbTable, totalTime, arr);
			if (result == 1)
				return 1;
			arr[j] -= people[i]->time;
		}
	}
	return 0;
}


int isPossible(struct s_people **people, int nbTable, int totalTime)
{
	int result;
	int *arr = malloc(nbTable * sizeof(int));
	result = recurse(people, 0, nbTable, totalTime, arr);
	free(arr);
	return result;
}