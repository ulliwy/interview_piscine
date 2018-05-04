/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junkFood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 20:49:23 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/05/03 22:56:41 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdlib.h>

struct s_sellers *closestSellers(struct s_graph *parisPlaces, char *youAreHere)
{
	struct s_node *start = NULL;
	for (int i = 0; parisPlaces->places[i]; i++)
	{
		if (strcmp(youAreHere, parisPlaces->places[i]->name) == 0)
		{
			start = parisPlaces->places[i];
			break;
		}
	}
	if (!start)
		return NULL;
	int dist = 0;
	int count = 0;
	struct s_node *temp;
	struct s_queue *q = queueInit();
	struct s_queue *bars = queueInit();
	enqueue(q, start);
	enqueue(q, NULL);
	while (q->first)
	{
		while ((temp = dequeue(q)))
		{
			temp->visited = 1;
			if (temp->hasCerealBar)
			{
				count++;
				enqueue(bars, temp);
			}
			else
			{
				for (int j = 0; temp->connectedPlaces[j]; j++)
					if (temp->connectedPlaces[j]->visited != 1)
					{
						temp->connectedPlaces[j]->visited = 1;
						enqueue(q, temp->connectedPlaces[j]);
					}
			}
		}
		enqueue(q, NULL);
		if (count)
			break;
		dist++;
	}

	struct s_sellers *sellers = malloc(sizeof(struct s_sellers));
	sellers->distance = dist;
	sellers->placeNames = malloc(sizeof(char *) * count + 1);
	for (int i = 0; i < count; i++)
		sellers->placeNames[i] = dequeue(bars)->name;
	sellers->placeNames[count] = NULL;
	return sellers;
}
