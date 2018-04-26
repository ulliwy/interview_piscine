/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:04:22 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/26 13:01:28 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <limits.h>
#include <stdlib.h>

#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)
// struct s_node {
// 	int value;
// 	struct s_node *right;
// 	struct s_node *left;
// };

// struct s_info {
// 	int min;        // the minimum value in the tree
// 	int max;        // the max value in the tree
// 	int elements;   // the number of nodes in the tree
// 	int height;     // the height of the tree
// 	int isBST;      // 0 = FALSE, 1 = TRUE
// 	int isBalanced; // 0 = FALSE, 1 = TRUE
// };

int getMin(struct s_node *root)
{
	int current;
	int left;
	int right;

	if (!root)
		return INT_MAX;
	current = root->value;
	left = getMin(root->left);
	right = getMin(root->right);
	if (current < left && current < right)
		return current;
	if (left < current && left < right)
		return left;
	return right;
}

int getMax(struct s_node *root)
{
	int current;
	int left;
	int right;

	if (!root)
		return INT_MIN;
	current = root->value;
	left = getMax(root->left);
	right = getMax(root->right);
	if (current > left && current > right)
		return current;
	if (left > current && left > right)
		return left;
	return right;
}

int isBST(struct s_node *root)
{
	if (!root)
		return 1;
	if (root->left && getMax(root->left) > root->value)
		return 0;
	if (root->right && getMin(root->right) <= root->value)
		return 0;
	if (!isBST(root->left) || !isBST(root->right))
		return 0;
	return 1;
}

int getSize(struct s_node *root)
{
	if (!root)
		return 0;
	return getSize(root->left) + getSize(root->right) + 1;
}

int getHeight(struct s_node *root)
{
	if (!root)
		return 0;
	return max(getHeight(root->left), getHeight(root->right)) + 1;
}

int isBalanced(struct s_node *root, int *h)
{
	int l = 0, r = 0;
	int lh = 0, rh = 0;
	if (!root)
	{
		*h = 0;
		return 1;
	}
	l = isBalanced(root->left, &lh);
	r = isBalanced(root->right, &rh);
	*h = max(lh, rh) + 1;
	if (lh -rh > 1 || rh - lh > 1)
		return 0;
	else
		return l && r;
}

struct s_info getInfo(struct s_node *root)
{
	struct s_info info;
	int height = 0;

	info.min = getMin(root);
	info.max = getMax(root);
	info.elements = getSize(root);
	info.height = getHeight(root);
	info.isBST = isBST(root);
	info.isBalanced = isBalanced(root, &height);
	return info;
}
