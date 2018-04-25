/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyGameBoard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 22:13:08 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/04/24 23:16:39 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

// struct s_node {
// 	int value;
// 	struct s_node *random;
// 	struct s_node *next;
// };

int listLen(struct s_node *node)
{
	int len = 0;
	while (node)
	{
		node = node->next;
		len++;
	}
	return len;
}

struct s_node *cloneGameBoard(struct s_node *node)
{
	struct s_node *tmp = node;
	struct s_node *new = NULL;
	struct s_node *res;
	struct s_node *prev = NULL;
	int len = listLen(node);
	struct s_node *table[len];

	while (tmp)
	{
		new = malloc(sizeof(struct s_node));
		new->value = tmp->value;
		new->random = NULL;
		if (prev)
			prev->next = new;
		else
			res = new;
		tmp = tmp->next;
		prev = new;
		table[new->value] = new;
	}
	tmp = node;
	while (tmp)
	{
		if (tmp->random)
			table[tmp->value]->random = table[tmp->random->value];
		tmp = tmp->next;
	}

	return res;
}