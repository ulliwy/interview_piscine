/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:02:59 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/24 00:15:11 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

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
	struct s_item *temp;

	temp = dict->items[k];
	while (temp)
	{
		if (!strcmp(key, temp->key))
		{
			//fprintf(stderr, "%s %d\n", key, temp->value);
			return (k);
		}
		temp = temp->next;
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
	int i = 0;
	int j = 0;
	int jj = 0;
	//int word_size = 0;
	char *word;
	int hash_num;

	while (book[j])
	{
		while (!isalnum(book[j]) && book[j])
		{
			//printf("space\n");
			book[i] = book[j];
			i++;
			j++;
		}
		//printf("j: %d\n", j);
		jj = j;
		while (isalnum(book[jj]) && book[jj])
			jj++;
		jj--;
		int word_len = jj - j + 1;
		word = (char *)calloc(1, word_len + 1);

		strncpy(word, book + j, word_len);
		//fprintf(stderr, "%s\n", word);
		if ((hash_num = dictSearch(dict, word)) != -1)
		{
			//fprintf(stderr, "<<<<<here1>>>>>>\n");
			//printf("i: %d, j: %d, len: %d\n", i, j, jj - j + 1);
			book[i] = '@';
			//printf("here:%d\n", hash_num);
			book[i + 1] = hash_num + 1;
			i = i + 2;
			//printf("i: %d, j: %d, len: %d\n", i, j, jj - j + 1);
			//printf("%s\n", word);
		}
		else
		{
			//"here is come hjjhjjh with jj   every  "
			//"come in"
			//printf("here2\n");
			//printf("i: %d, j: %d, len: %d\n", i, j, jj - j + 1);
			if (i != j)
			{
				//printf("here3\n");
				memmove(book + i, book + j, word_len);
			}
			i = i + word_len;
		}
		free(word);
		j = jj + 1;
		//printf("%d\n", j);
	}
	printf("i: %d, j: %d\n", i, j);
	while (book[i])
	{
		book[i] = '\0';
		i++;
	}
	//printf("<%s>\n", book);

	return (book);
}
