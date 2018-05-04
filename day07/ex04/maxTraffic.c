/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxTraffic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 11:59:45 by iprokofy          #+#    #+#             */
/*   Updated: 2018/05/04 13:01:50 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// struct s_node {
// 	char *name;
// 	int population;
// 	int visited; //0 = FALSE, 1 = TRUE
// 	struct s_node **connectedPlaces;
// };

// struct s_queueItem {
//   void *item;
//   struct s_queueItem *next;
// };

// struct s_queue {
//   struct s_queueItem *first;
//   struct s_queueItem *last;
// };

// void enqueue(struct s_queue *queue, void *item);
// void *dequeue(struct s_queue *queue);
// struct s_queue *queueInit(void);

// struct s_graph {
//     struct s_node **places;
// };

float maxTraffic(struct s_graph *parisPlaces, char *eventHere)
{
	printf("here\n");
	struct s_node *start = NULL;
	for (int i = 0; parisPlaces->places[i]; i++)
	{
		if (strcmp(eventHere, parisPlaces->places[i]->name) == 0)
		{
			start = parisPlaces->places[i];
			break;
		}
	}
	if (!start)
	{
		printf("NO\n");
		return -1.0;
	}
	struct s_queue *q = queueInit();
	struct s_node *temp;
	//struct s_node place;
	float pop = 0;
	int count;
	for (int i = 0; start->connectedPlaces[i]; i++)
	{
		start->connectedPlaces[i]->visited = 1;
		enqueue(q, start->connectedPlaces[i]);
		if (start->connectedPlaces[i]->population > pop)
			pop = start->connectedPlaces[i]->population;
	}
	while ((temp = dequeue(q)))
	{
		temp->visited = 1;
		count = 0;
		for (int i = 0; temp->connectedPlaces[i]; i++)
		{
			if temp->connectedPlaces[i]->visited == 
		}
	}

	while ((temp = dequeue(q)))
		printf("%s\n", temp->name);
	return -1.0;
}
