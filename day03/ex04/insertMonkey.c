/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertMonkey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 23:08:46 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/04/27 17:46:38 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

struct s_node *dequeue(struct s_queue *queue)
{
	struct s_node *node = NULL;
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

int getArray(struct s_node *root, struct s_node **arr, int *i, struct s_node *monkey)
{
	struct s_queue *q = queueInit();
	struct s_node *node;
	int set = 0;
	int pos = 0;

	if (!root)
		return 0 ;
	enqueue(q, root);
	while ((node = dequeue(q)))
	{
		//printf("i: %d\n", *i);
		arr[*i] = node;
		(*i)++;
		if (!node->left && !set)
		{
			node->left = monkey;
			pos = *i;
			set = 1;
		}
		else
			enqueue(q, node->left);
		if (!node->right && !set)
		{
			node->right = monkey;
			set = 1;
		}
		else
			enqueue(q, node->right);
	}
	return pos;
}

void swap(struct s_node **parent, struct s_node **child)
{
	printf("IN SWAP:\n");
	printf("%d %d\n", (*parent)->value, (*child)->value);
	struct s_node *temp = *parent;
	struct s_node *childLeft = (*child)->left;
	struct s_node *childRight = (*child)->right;
	*parent = *child;
	if (temp->left == *child)
	{
		(*child)->left = temp;
		(*child)->right = temp->right;
	}
	else
	{
		(*child)->right = temp;
		(*child)->left = temp->left;
	}
	temp->left = childLeft;
	temp->right = childRight;
	*child = temp;
	printf("%d %d\n", (*parent)->value, (*child)->value);
	printf("%d\n", (*parent)->left->value);
}

void popNode(struct s_node **arr, int size)
{
	while (size > 1)
	{
		if (arr[size]->value > arr[size - 1]->value)
		{
			swap(&(arr[size - 1]), &(arr[size]));
		}
		else
			return;
		size--;
	}
	return;
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
	if (!(!monkey->left && !monkey->right))
		return;
	if (!root)
		return;
	int size = getSize(*root);
	//printf("size: %d\n", size);
	struct s_node **arr = malloc(sizeof(struct s_node *) * (size + 1));
	int i = 0;
	int pos = getArray(*root, arr, &i, monkey);
	arr[size] = monkey;
	printBinaryTree(*root);
	i = pos;
	for (i = 0; i <=size; i++)
		printf("%d:%d ", i, arr[i]->value);
	printf("\n");
	//int parent(int i) { return (i-1)/2; }
	//struct s_node *temp;

	// while (i != 0 && harr[parent(i)] > harr[i])
 //    {
 //       swap(&harr[i], &harr[parent(i)]);
 //       i = parent(i);
 //    }
	//printf("arr[0]: %d, arr[1]: %d\n", arr[0]->value, arr[1]->value);
	//swap(root, &(*root)->left);
	//printf("SWAP RESULT\n");
	//printBinaryTree(*root);
	i = size;
	while (i != 0 && arr[parent(i)]->value < arr[i]->value)
	{
		printf("SWAP RESULT\n");
		printf("swapping indexes: %d and %d\n", parent(i), i);
		swap(&(arr[parent(i)]), &(arr[i]));
		printf("%d %d\n", arr[parent(i)]->value, arr[i]->value);
		printBinaryTree(*root);
		break;
	}
	// i = size;
	// while (i != 0 && arr[parent(i)]->value < arr[i]->value)
	// {
	// 	// temp = arr[i];
	// 	// arr[i] = arr[i - 1];
	// 	// arr[i - 1] = temp;
	// 	printf("SWAP RESULT\n");
	// 	printf("parent index: %d\n", parent(i));
	// 	if (arr[parent(i)]->left == arr[i] || arr[parent(i)]->right == arr[i])
	// 		printf("PARENT\n");
	// 	swap(&(arr[parent(i)]), &(arr[i]));
	// 	printBinaryTree(*root);
	// 	i = parent(i);
	// }
	// if (size > 1)
	// {
	// 	if (!arr[size - 1]->left)
	// 	{
	// 		arr[size - 1]->left = arr[size];
	// 	}
	// 	else
	// 	{
	// 		arr[size - 1]->right = arr[size];
	// 	}
	// }
	//popNode(arr, size);
	// i = 0;
	// for (i = 0; i <=size; i++)
	// 	printf("%d:%d ", i, arr[i]->value);
	// printf("\n");

}
