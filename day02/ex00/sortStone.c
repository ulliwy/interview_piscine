/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 09:01:46 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/04/25 09:52:09 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

void split(struct s_stone *head, struct s_stone **left, struct s_stone **right)
{
	struct s_stone *first = head;
	struct s_stone *second = head->next;

	while (second)
	{
		second = second->next;
		if (second)
		{
			second = second->next;
			first = first->next;
		}
	}
	*left = head;
	*right = first->next; // odd node goes to left
	first->next = NULL; //to stop the list
}

struct s_stone *merge(struct s_stone *left, struct s_stone *right)
{
	struct s_stone *merged = NULL;
	if (!left)
		return right;
	if (!right)
		return left;

	if (left->size <= right->size)
	{
		merged = left;
		merged->next = merge(left->next, right);
	}
	else
	{
		merged = right;
		merged->next = merge(left, right->next);
	}
	return merged;
}

// implementing merge sort nlogn
void sortStones(struct s_stone **stone)
{
	if (!stone)
		return;
	struct s_stone *head = *stone;
	struct s_stone *left;
	struct s_stone *right;

	if (!head || !head->next)
		return;
	split(head, &left, &right);
	sortStones(&left);
	sortStones(&right);
	*stone = merge(left, right);
}
