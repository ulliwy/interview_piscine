/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:02:59 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/23 17:37:36 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//FNV-1
size_t hash(char *input)
{
	int i = 101;
	while (*input)
	{
		i = i * 1099511628211;
		i = i ^ (*input);
		input++;
	}
	return i;
}

int	dictInsert(struct s_dict *dict, char *key, int value)
{
	size_t k = hash(key) % dict->capacity;
	
	if (!dict->items[k])
	{
		dict->items[k] = (struct s_item *)malloc(sizeof(struct s_item));
		if (!dict->items[k])
			return (0);
		dict->items[k]->key = strdup(key);
		dict->items[k]->value = value;
		dict->items[k]->next = NULL;
	}
	else
	{
		struct s_item *tmp = dict->items[k];
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (struct s_item *)malloc(sizeof(struct s_item));
		tmp->next->key = strdup(key);
		if (!tmp->next || !tmp->next->key)
			return (0);
		tmp->next->value = value;
		tmp->next->next = NULL;
	}	
	return (1);
}

int	dictSearch(struct s_dict *dict, char *key)
{
	int k = hash(key) % dict->capacity;
	while (dict->items[k])
	{
		if (!strcmp(key, dict->items[k]->key))
		{
			//printf("%s %s\n", key, dict->items[k]->value->name);
			return (dict->items[k]->value);
		}
		dict->items[k] = dict->items[k]->next;
	}
	return(-1);

}

struct s_dict *dictInit(int capacity)
{
	struct s_dict *dict = (struct s_dict *)malloc(sizeof(struct s_dict));

	dict->capacity = capacity;
	dict->items = (struct s_item **)calloc(capacity, sizeof(struct s_item *));
	return (dict);
}

char *compress(char *book, struct s_dict *dict)
{
	return (NULL);
}
