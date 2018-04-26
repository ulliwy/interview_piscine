/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findParent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:20:42 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/26 16:09:44 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// struct s_node {
// 	char	*name;
// 	struct s_node **children;
// };

int getHeight(struct s_node *root)
{
	int i = 0;
	int height = 0;
	int current = 0;

	if (!root)
		return 0;
	while (root->children[i])
	{
		height = getHeight(root->children[i]);
		if (height > current)
			current = height;
	}
	return current + 1;
}

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	firstSpecies = NULL;
	secondSpecies = NULL;
	int height = getHeight(root);
	printf("%d\n", height);
	return NULL;
}

// struct s_node *findLCABT(struct s_node *root, char *firstSpecies, char *secondSpecies, int *first, int *second)
// {
// 	struct s_node *left;
// 	struct s_node *right;
// 	if (!root)
// 		return NULL;
// 	if (!strcmp(root->name, firstSpecies))
// 	{
// 		*first = 1;
// 		return root;
// 	}
// 	if (!strcmp(root->name, secondSpecies))
// 	{
// 		*second = 1;
// 		return root;
// 	}
// 	left = findLCA(root->left, firstSpecies, secondSpecies, first, second);
// 	right = findLCA(root->right, firstSpecies, secondSpecies, first, left);

// 	if (left && right) // both not NULL, so nodes in both subtrees
// 		return root;
// 	if (left)
// 		return left;
// 	return right;
// }

// int findNode(struct s_node *root, char *value)
// {
// 	if (!root)
// 		return 0;
// 	if (!strcmp(root->name, value))
// 		return 1;
// 	if (findNode(root->left, value) || findNode(root->right, value))
// 		return 1;
// 	return 0;
// }

// struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
// {
// 	struct s_node *node = NULL;
// 	int first = 0;
// 	int second = 0;

// 	node = findLCABT(root, firstSpecies, secondSpecies, &first, &second);
// 	if (first && second)
// 		return node;
// 	if (first && findNode(node, secondSpecies))
// 		return node;
// 	if (second && findNode(node, firstSpecies))
// 		return node;
// 	return NULL;
// }