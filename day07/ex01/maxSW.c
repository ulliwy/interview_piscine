/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxSW.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 12:02:12 by iprokofy          #+#    #+#             */
/*   Updated: 2018/05/03 16:49:40 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

struct s_deque *dequeInit(void)
{
	struct s_deque *q = malloc(sizeof(struct s_deque));
	if (!q)
		return NULL;
	q->first = NULL;
	q->last = NULL;
	return q;
}

void pushFront(struct s_deque *deque, int value)
{
	if (!deque)
		return;

	struct s_dequeNode *new = malloc(sizeof(struct s_dequeNode));
	if (!new)
		return;

	new->value = value;
	if (!deque->first)
	{
		new->next = NULL;
		new->prev = NULL;
		deque->first = new;
		deque->last = new;
	}
	else
	{
		new->next = deque->first;
		new->prev = NULL;
		deque->first->prev = new;
		deque->first = new;
	}
}

void pushBack(struct s_deque *deque, int value)
{
	if (!deque)
		return;

	struct s_dequeNode *new = malloc(sizeof(struct s_dequeNode));
	if (!new)
		return;

	new->value = value;

	if (!deque->last)
	{
		new->next = NULL;
		new->prev = NULL;
		deque->last = new;
		deque->first = new;
	}
	else
	{
		new->next = NULL;
		new->prev = deque->last;
		deque->last->next = new;
		deque->last = new;
	}
}

int popFront(struct s_deque *deque)
{
	struct s_dequeNode *tmp;
	int value;

	if (!deque)
		return INT_MIN;
	if (!deque->first)
		return INT_MIN;
	value = deque->first->value;
	tmp = deque->first;
	deque->first = deque->first->next;

	if (!deque->first)
		deque->last = NULL;
	else
		deque->first->prev = NULL;
	free(tmp);
	return value;
}

int popBack(struct s_deque *deque)
{
	struct s_dequeNode *tmp;
	int value;

	if (!deque)
		return INT_MIN;
	if (!deque->last)
		return INT_MIN;
	value = deque->last->value;
	tmp = deque->last;
	deque->last = deque->last->prev;
	if (!deque->last)
		deque->first = NULL;
	else
		deque->last->next = NULL;
	free(tmp);
	return value;
}

int peekBack(struct s_deque *deque)
{
	if (!deque)
		return INT_MIN;
	if (!deque->last)
		return INT_MIN;
	return deque->last->value;
}

int peekFront(struct s_deque *deque)
{
	if (!deque)
		return INT_MIN;
	if (!deque->first)
		return INT_MIN;
	return deque->first->value;
}

struct s_max *maxSlidingWindow(int *arr, int n, int k)
{
	if (k > n || k < 0)
		return NULL;
	struct s_deque *q = dequeInit();
	struct s_max *result = malloc(sizeof(struct s_max));
	result->max = malloc(sizeof(int) * (n - k + 1));
	result->length = n - k + 1;

	int i;

	for (i = 0; i < k; i++)
	{
		while (q->last && peekBack(q) != INT_MIN && arr[i] >= arr[peekBack(q)])
			popBack(q);
		pushBack(q, i);
	}

	for (i = k; i < n; i++)
	{
		result->max[i - k] = arr[peekFront(q)];
		while (q->first && peekFront(q) != INT_MIN && peekFront(q) <= i - k)
			popFront(q);
		while (q->last && peekBack(q) != INT_MIN && arr[i] >= arr[peekBack(q)])
			popBack(q);
		pushBack(q, i);
	}
	result->max[i - k] = arr[peekFront(q)];

	return result;
}
