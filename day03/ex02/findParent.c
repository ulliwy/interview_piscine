/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findParent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:20:42 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/26 20:12:40 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct s_node *findLCA(struct s_node *root, char *firstSpecies, char *secondSpecies, int *first, int *second)
{
	struct s_node *child = NULL;
	int i;
	int count = 0;

	if (!root)
		return NULL;
	if (!strcmp(root->name, firstSpecies))
	{
		*first = 1;
		return root;
	}
	if (!strcmp(root->name, secondSpecies))
	{
		*second = 1;
		return root;
	}
	i = 0;

	while (root->children[i])
	{
		struct s_node *temp = findLCA(root->children[i], firstSpecies, secondSpecies, first, second);
		if (temp)
		{
			child = temp;
			count++;
		}
		i++;
	}
	if (count == 2)
		return root;
	return child;
}

int findNode(struct s_node *root, char *value)
{
	int i = 0;

	if (!root)
		return 0;
	if (!strcmp(root->name, value))
		return 1;
	while (root->children[i])
	{
		if (findNode(root->children[i], value))
			return 1;
		i++;
	}
	return 0;
}

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	struct s_node *node = NULL;
	int first = 0;
	int second = 0;

	node = findLCA(root, firstSpecies, secondSpecies, &first, &second);
	if (first && second)
		return node;
	if (first && findNode(node, secondSpecies))
		return node;
	if (second && findNode(node, firstSpecies))
		return node;
	return NULL;
}