/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 10:45:21 by iprokofy          #+#    #+#             */
/*   Updated: 2018/05/03 11:28:45 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

void heapify(struct s_art **arr, int i, int n)
{
	struct s_art *temp;
	int root = i;
	int left = 2 * i + 1;
	int right = left + 1;

	if (left < n && strcmp(arr[left]->name, arr[root]->name) > 0)
		root  = left;

	if (right < n && strcmp(arr[right]->name, arr[root]->name) > 0)
		root  = right;

	if (root != i)
	{
		temp = arr[i];
		arr[i] = arr[root];
		arr[root] = temp;

		heapify(arr, root, n);
	}
}

void heapSort(struct s_art **masterpiece, int n)
{
	struct s_art *temp;
	
	//create max heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(masterpiece, i, n);

	//extract elements from heap
	for (int i = n - 1; i >= 0; i--)
	{
		temp = masterpiece[0];
		masterpiece[0] = masterpiece[i];
		masterpiece[i] = temp;

		heapify(masterpiece, 0, i);
	}
}