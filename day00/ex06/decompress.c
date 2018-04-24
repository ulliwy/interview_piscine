/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 00:29:54 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/04/24 11:50:47 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

struct s_string *stringInit(void) //success: return new allocated pointer, fail: return NULL
{
	struct s_string *new;

	new = calloc(1, sizeof(struct s_string));
	if (!new)
		return NULL;
	new->content = (char *)calloc(1, 10 + 1);
	new->capacity = 10;
	new->length = 0;
	return (new);
}

int stringAppend(struct s_string *dyString, char *str) //success: return 1, fail: return 0
{
	int len = strlen(str);
	if (len <= dyString->capacity - dyString->length)
	{
		strncpy(dyString->content + dyString->length, str, len);
		dyString->length += len;
	}
	else
	{
		char *new = calloc(1, dyString->capacity * 2 + len + 1);
		strcpy(new, dyString->content);
		free(dyString->content);
		dyString->content = new;
		dyString->capacity = dyString->capacity * 2 + len;
		strncpy(dyString->content + dyString->length, str, len);
		dyString->length += len;
	}
	return 1;
}

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
	size_t k = value % dict->capacity;
	
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

char *dictSearch(struct s_dict *dict, int k)
{
	struct s_item *temp;

	temp = dict->items[k];
	if (k > 0 && k < 256 && dict->items[k])
		return (temp->key);
	return(NULL);

}

struct s_dict *dictInit(int capacity)
{
	struct s_dict *dict = (struct s_dict *)malloc(sizeof(struct s_dict));

	dict->capacity = capacity;
	dict->items = (struct s_item **)calloc(capacity, sizeof(struct s_item *));
	return (dict);
}

char *decompress(char *cBook)
{
	struct s_dict *dict = dictInit(256);

	struct s_string *str = stringInit();
	int i = 1;
	char *word = malloc(20);
	int count = 1;
	int j = 0;
	while (cBook[i] != '>' && cBook[i])
	{
		if (cBook[i] != ',')
		{
			word[j] = cBook[i];
			j++;
		}
		else
		{
			word[j] = '\0';
			j = 0;
			dictInsert(dict, word, count);
			count++;
		}
		i++;
	}
	i++;
	word[j] = '\0';
	dictInsert(dict, word, count);
	cBook = cBook + i;
	i = 0;
	while (cBook[i])
	{
		j = i;
		while (cBook[i] && cBook[i] != '@')
		{
			i++;
		}
		cBook[i] = '\0';
		stringAppend(str, cBook + j);
		char *hash;
		if ((hash = dictSearch(dict, cBook[i + 1])))
			stringAppend(str, hash);
		cBook[i + 1] = '\0';
		i += 2;
	}
	printf("%s", str->content);
	return cBook;
}