/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 09:01:46 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/04/25 17:12:03 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

int getLen(struct s_stone **stone)
{
	struct s_stone *node = *stone;
	int i = 0;
	if (!stone)
		return 0;
	while (node)
	{
		i++;
		node = (node)->next;
	}
	return i;
}

void sortStones(struct s_stone **stone)
{
	int size = getLen(stone);
	struct s_stone **arr;
	int temp;
	struct s_stone *node = *stone;
	struct s_stone *temp_node;
	struct s_stone *last = NULL;
	int i;
	int groups;

	if (!stone)
		return;
	arr = calloc(1, sizeof(struct s_stone *) * size);
	temp = node->size;
	arr[0] = node;
	i = 1;
	node = node->next;
	while (node)
	{
		if (temp != node->size)
		{
			temp = node->size;
			arr[i] = node;
			i++;
		}
		node = node->next;
	}
	groups = i;
	for (i = 0; i < groups; i++)
	{
		for (int j = 0; j < groups; j++)
		{
			if (arr[i]->size < arr[j]->size)
			{
				temp_node = arr[i];
				arr[j] = arr[i];
				arr[i] = temp_node;
			}
		}
	}
	for (i = 0; i < groups; i++)
	{
		if (last)
			last->next = arr[i];
		while(arr[i])
		{
			if (!arr[i]->next)
			{
				last = arr[i];
				break;
			}
			if (arr[i]->size != arr[i]->next->size)
			{
				last = arr[i];
				break;
			}
			arr[i] = arr[i]->next;
		}
		if (i == groups - 1)
			arr[i] = NULL;
	}
	*stone = arr[0];
	free(arr);
}

// void split(struct s_stone *head, struct s_stone **left, struct s_stone **right)
// {
// 	struct s_stone *first = head;
// 	struct s_stone *second = head->next;

// 	while (second)
// 	{
// 		second = second->next;
// 		if (second)
// 		{
// 			second = second->next;
// 			first = first->next;
// 		}
// 	}
// 	*left = head;
// 	*right = first->next; // odd node goes to left
// 	first->next = NULL; //to stop the list
// }

// struct s_stone *merge(struct s_stone *left, struct s_stone *right)
// {
// 	struct s_stone *merged = NULL;
// 	if (!left)
// 		return right;
// 	if (!right)
// 		return left;

// 	if (left->size <= right->size)
// 	{
// 		merged = left;
// 		merged->next = merge(left->next, right);
// 	}
// 	else
// 	{
// 		merged = right;
// 		merged->next = merge(left, right->next);
// 	}
// 	return merged;
// }

// // implementing merge sort nlogn
// void sortStones(struct s_stone **stone)
// {
// 	if (!stone)
// 		return;
// 	struct s_stone *head = *stone;
// 	struct s_stone *left;
// 	struct s_stone *right;

// 	if (!head || !head->next)
// 		return;
// 	split(head, &left, &right);
// 	sortStones(&left);
// 	sortStones(&right);
// 	*stone = merge(left, right);
// }
