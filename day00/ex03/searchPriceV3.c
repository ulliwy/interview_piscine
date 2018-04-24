/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 12:20:24 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/24 10:15:39 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int getSize(struct s_art **arts)
{
	int i = 0;

	while(arts[i])
		i++;
	return i;
}

size_t hash(char *input)
{
	size_t i = 0;
	while (*input)
	{
		i += *input;
		input++;
	}
	return i;
}

struct s_dict *dictInit(int capacity)
{
	struct s_dict *dict = (struct s_dict *)malloc(sizeof(struct s_dict));

	dict->capacity = capacity;
	dict->items = (struct s_item **)calloc(capacity, sizeof(struct s_item *));
	return (dict);
}

int dictInsert(struct s_dict *dict, char *key, struct s_art *value)
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

struct s_art *dictSearch(struct s_dict *dict, char *key)
{
	int k = hash(key) % dict->capacity;
	struct s_item *temp;

	temp = dict->items[k];
	while (temp)
	{
		if (!strcmp(key, temp->value->name))
			return (temp->value);
		temp = temp->next;
	}
	return(NULL);

}

void test(struct s_art **arts)
{
	struct s_dict *dict = dictInit(1000);
	int i = 0;
	while(arts[i])
	{
		dictInsert(dict, arts[i]->name, arts[i]);
		i++;
	}

	struct s_art *test = dictSearch(dict, "Mona Lisk");
	if (test)
		printf("%s\n", test->name);
	else 
		printf("no\n");

	test = dictSearch(dict, "Mona Lisa");
	if (test)
		printf("%s\n", test->name);
	else 
		printf("no\n");

	test = dictSearch(dict, "No!!!");
	if (test)
		printf("%s\n", test->name);
	else 
		printf("no\n");

	// additional tests are below

	// struct s_dict *dict = dictInit(5);
	// dictInsert(dict, arts[0]->name, arts[0]);
	// dictInsert(dict, arts[1]->name, arts[1]);
	// dictInsert(dict, arts[2]->name, arts[2]);
	// dictInsert(dict, arts[3]->name, arts[3]);

	// int i = 0;
	// while (i < 5)
	// {
	// 	struct s_item *tmp = dict->items[i];
	// 	while (tmp)
	// 	{
	// 		printf("%zu %s %s\n", hash(tmp->key), tmp->key, tmp->value->name);
	// 		tmp = tmp->next;
	// 	}
	// 	i++;
	// }
	// printf("\n");

	// struct s_art *test = dictSearch(dict, "aak");
	// if (test)
	// 	printf("%s\n", test->name);
	// else 
	// 	printf("no\n");

	// test = dictSearch(dict, "aal");
	// if (test)
	// 	printf("%s\n", test->name);
	// else 
	// 	printf("no\n");
	// free(dict);
}
