/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 13:27:00 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/24 15:13:11 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

// # define CS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 !?:;,.$&<>()+*-_="

// struct s_node {
// 	char c;
// 	struct s_node *prev;
// 	struct s_node *next;
// };

struct s_node *createElem(char c)
{
	struct s_node *list;

	list = (struct s_node *)malloc(sizeof(struct s_node));
	list->c = c;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

void insertAfter(struct s_node **head, char c)
{
	if (*head == NULL)
	{
		*head = createElem(c);
		(*head)->next = (*head);
		(*head)->prev = (*head);
		return;
	}
	struct s_node *node = createElem(c);
	node->next = *head;
	node->prev = (*head)->prev;
	(*head)->prev->next = node;
	(*head)->prev = node;
}

char *precious(int *text, int size)
{
	if (size < 0)
		return (NULL);
	char *str = malloc(size + 1);
	struct s_node *list = NULL;
	int i = 0;
	while (i < 80)
	{
		insertAfter(&list, CS[i]);
		i++;
	}
	i = 0;
	int rot = 0;
	while (i < size)
	{
		rot = text[i];
		if (rot >= 0)
		{
			while (rot--)
				list = list->next;
		}
		else
		{
			while (rot++)
				list = list->prev;
		}
		str[i] = list->c;
		i++;
	}
	str[i] = '\0';
	return str;
}
