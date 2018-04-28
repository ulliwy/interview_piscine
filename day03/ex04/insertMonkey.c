/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertMonkey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 23:08:46 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/04/28 10:04:07 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

struct s_node **dequeue(struct s_queue *queue)
{
	struct s_node **node = NULL;
	struct s_item *tmp;

	if (!queue)
		return NULL;
	if (!queue->first)
		return NULL;
	node = queue->first->node;
	tmp = queue->first;
	queue->first = queue->first->next;
	if (!queue->first)
		queue->last = NULL;
	free(tmp);
	return node;
}

void enqueue(struct s_queue *queue, struct s_node **monkey)
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

struct s_node **getArray(struct s_node **root, struct s_node ***arr, int *i, struct s_node *monkey)
{
	struct s_queue *q = queueInit();
	struct s_node **node;
	struct s_node **monkey_pos;
	int set = 0;
	int pos = 0;

	if (!root)
		return 0 ;
	enqueue(q, root);
	while ((node = dequeue(q)) && *node)
	{
		arr[*i] = node;
		(*i)++;
		if (!(*node)->left && !set)
		{
			monkey_pos = &(*node)->left;
			(*node)->left = monkey;
			pos = *i;
			set = 1;
		}
		else
			enqueue(q, &(*node)->left);
		if (!(*node)->right && !set)
		{
			monkey_pos = &(*node)->right;
			(*node)->right = monkey;
			set = 1;
		}
		else
			enqueue(q, &(*node)->right);
	}

	return monkey_pos;
}

void swap(struct s_node ***parent_ptr, struct s_node ***child_ptr)
{
	struct s_node **parent = *parent_ptr; // no real need in ***parent_ptr, just for sake of symmetry
	struct s_node **child = *child_ptr;

	struct s_node *temp = *parent;
	struct s_node *childLeft = (*child)->left;
	struct s_node *childRight = (*child)->right;
	*parent = *child;
	if (temp->left == *child)
	{
		*child_ptr = &(*child)->left;
		(*child)->left = temp;
		(*child)->right = temp->right;
	}
	else
	{
		*child_ptr = &(*child)->right;
		(*child)->right = temp;
		(*child)->left = temp->left;
	}
	temp->left = childLeft;
	temp->right = childRight;
}

int getSize(struct s_node *root)
{
	if (!root)
		return 0;
	return getSize(root->left) + getSize(root->right) + 1;
}

int parent(int i) { return (i-1)/2; }

void insertMonkey(struct s_node **root, struct s_node *monkey)
{
	int size = getSize(*root);
	struct s_node ***arr = malloc(sizeof(struct s_node **) * (size + 1));
	int i = 0;
	struct s_node **monkey_pos;

	if (!(!monkey->left && !monkey->right))
		return;
	if (!root)
		return;
	
	monkey_pos = getArray(root, arr, &i, monkey);
	arr[size] = monkey_pos;
	i = size;
	while (i != 0 && (*arr[parent(i)])->value < (*arr[i])->value)
	{
		swap(&arr[parent(i)], &arr[i]);
		i = parent(i);
	}
}
