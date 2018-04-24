/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:02:59 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/24 10:21:22 by iprokofy         ###   ########.fr       */
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
			return (k);
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

char *dictPrintHeader(struct  s_dict *dict, int *size)
{
	int len = 0;

	int i = 0;
	while (i < dict->capacity)
	{
		struct s_item *temp = dict->items[i];
		while (temp) 
		{
			len += strlen(temp->key) + 1;
			temp = temp->next;
		}
		i++;
	}
	len++;
	char *header = calloc(1, len + 1);
	*size = len;
	i = 0;
	header[0] = '<';
	char *h = header + 1;
	while (i < dict->capacity)
	{
		struct s_item *temp = dict->items[i];
		while (temp) 
		{
			int cur = strlen(temp->key);
			strncpy(h, temp->key, cur);
			h[cur] = ',';
			temp = temp->next;
			h = h + cur + 1;
		}
		i++;
	}
	*(h - 1) = '>';
	return header;
};

char *compress(char *book, struct s_dict *dict)
{
	int dict_size;
	char *header = dictPrintHeader(dict, &dict_size);
	int j = 0;
	int i = 0;
	char *new = malloc(strlen(book) + dict_size + 1);
	while (!isprint(book[j]) && book[j])
	{
		new[i] = book[j];
		i++;
		j++;
	}
	strncpy(new + i, header, dict_size);
	free(header);
	int jj = 0;
	char *word;
	int hash_num;
	i += dict_size;

	while (book[j])
	{
		while (!isalnum(book[j]) && book[j])
		{
			new[i] = book[j];
			i++;
			j++;
		}
		jj = j;
		while (isalnum(book[jj]) && book[jj])
			jj++;
		jj--;
		int word_len = jj - j + 1;
		word = (char *)calloc(1, word_len + 1);

		strncpy(word, book + j, word_len);
		if ((hash_num = dictSearch(dict, word)) != -1)
		{
			new[i] = '@';
			new[i + 1] = hash_num + 1;
			i = i + 2;
		}
		else
		{
			if (i != j)
			{
				strncpy(new + i, book + j, word_len);
			}
			i = i + word_len;
		}
		free(word);
		j = jj + 1;
	}
	while (new[i])
	{
		new[i] = '\0';
		i++;
	}

	return (new);
}
