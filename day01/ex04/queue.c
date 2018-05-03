/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 19:38:42 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/05/03 12:06:52 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

struct s_queue *queueInit(void)
{
	struct s_queue *q = malloc(sizeof(struct s_queue));
	if (!q)
		return NULL;
	q->first = NULL;
	q->last = NULL;
	return q;
}

char *dequeue(struct s_queue *queue)
{
	char *msg = NULL;
	struct s_node *tmp;

	if (!queue)
		return NULL;
	if (!queue->first)
		return NULL;
	msg = queue->first->message;
	tmp = queue->first;
	queue->first = queue->first->next;
	if (!queue->first)
		queue->last = NULL;
	free(tmp);
	return msg;
}

void enqueue(struct s_queue *queue, char *message)
{
	if (!queue)
		return;

	struct s_node *new = malloc(sizeof(struct s_node));
	if (!new)
		return;

	new->message = message;
	new->next = NULL;

	if (!queue->last)
	{
		queue->last = new;
		queue->first = new;
		return;
	}
	queue->last->next = new;
	queue->last = new;
}

char *peek(struct s_queue *queue)
{
	if (!queue)
		return NULL;
	if (!queue->first)
		return NULL;
	return queue->first->message;
}
int isEmpty(struct s_queue *queue)
{
	if (!queue)
		return 1;
	if (!queue->first)
		return 1;
	return 0;
}

