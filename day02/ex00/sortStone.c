/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 09:01:46 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/04/25 19:39:36 by Ulliwy           ###   ########.fr       */
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

int getBucketNum(struct s_stone *stone, struct s_stone **arr)
{
	int num = 0;
	int size = 0;

	if (!stone)
		return 0;
	while (stone)
	{
		if (stone->size != size)
		{
			if (arr)
				arr[num] = stone;
			size = stone->size;
			num++;
		}
		stone = stone->next;
	}
	return num;
}

void printArr(struct s_stone **arr, int size)
{
	for (int i=0;i<size;i++)
		printf("%d ", arr[i]->size);
	printf("\n");
}

void bubbleSort(struct s_stone **arr, int size)
{
	struct s_stone *temp;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i]->size < arr[j]->size)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

struct s_stone *getLast(struct s_stone *node)
{
	while (node->next && node->next->size == node->size)
		node = node->next;
	return node;
}

struct s_stone *reorder(struct s_stone **arr, int size)
{
	struct s_stone *node;

	for (int i = 0; i < size; i++)
	{
		node = getLast(arr[i]);
		if (i == size - 1)
			node->next = NULL;
		else
			node->next = arr[i + 1];
	}
	return arr[0];
}

void sortStones(struct s_stone **stone)
{
	int buckets = getBucketNum(*stone, NULL);
	struct s_stone *arr[buckets];

	getBucketNum(*stone, arr);
	bubbleSort(arr, buckets);
	*stone = reorder(arr, buckets);
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
