/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertMonkey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 23:08:46 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/04/26 23:43:06 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

// char *dequeue(struct s_queue *queue)
// {
// 	char *msg = NULL;
// 	struct s_node *tmp;

// 	if (!queue)
// 		return NULL;
// 	if (!queue->first)
// 		return NULL;
// 	msg = queue->first->message;
// 	tmp = queue->first;
// 	queue->first = queue->first->next;
// 	if (!queue->first)
// 		queue->last = NULL;
// 	free(tmp);
// 	return msg;
// }

// char *peek(struct s_queue *queue)
// {
// 	if (!queue)
// 		return NULL;
// 	if (!queue->first)
// 		return NULL;
// 	return queue->first->message;
// }
// int isEmpty(struct s_queue *queue)
// {
// 	if (!queue)
// 		return 1;
// 	if (!queue->first)
// 		return 1;
// 	return 0;
// }

// struct s_node {
// 	int value;
// 	struct s_node *right;
// 	struct s_node *left;
// };

// struct s_item {
//   struct s_node *node;
//   struct s_item *next;
// };

// struct s_queue {
//   struct s_node *first;
//   struct s_node *last;
// };

void enqueue(struct s_queue *queue, struct s_node *monkey)
{
	if (!queue)
		return;

	struct s_item *new = malloc(sizeof(struct s_item));
	if (!new)
		return;

	new->node = monkey;
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

struct s_queue *queueInit(void)
{
	struct s_queue *q = malloc(sizeof(struct s_queue));
	if (!q)
		return NULL;
	q->first = NULL;
	q->last = NULL;
	return q;
}

struct s_node *addNode(struct s_node *root, struct s_node *monkey)
{
	struct s_queue *q = queueInit();

	if (!root)
		return monkey;
	enqueue(q, root);
	return NULL;
	
}

void insertMonkey(struct s_node **root, struct s_node *monkey)
{
	if (!root)
		return;
	struct s_node *parent = addNode(*root, monkey);
	parent = NULL;
}
