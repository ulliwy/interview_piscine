/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:16:58 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/26 14:14:42 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

struct s_node *createNode(int value)
{
	struct s_node *node = malloc(sizeof(struct s_node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct s_node *insertNode(int *arr, int left, int right)
{
	struct s_node *node;

	int mid = left + (right - left) / 2;
	if (left > right)
		return NULL;
	node = createNode(arr[mid]);
	node->left = insertNode(arr, left, mid - 1);
	node->right = insertNode(arr, mid + 1, right);
	return node;
}

struct s_node *createBST(int *arr, int n)
{
	struct s_node *node = NULL;

	if (n <= 0)
		return node;

	return insertNode(arr, 0, n - 1);
}
