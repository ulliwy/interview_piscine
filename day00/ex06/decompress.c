/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 00:29:54 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/04/24 00:52:29 by Ulliwy           ###   ########.fr       */
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

char *decompress(char *cBook)
{
	struct s_string *str = stringInit();
	stringAppend(str, "hellofffff");
	stringAppend(str, "");
	printf("<%s>\n", str->content);

	return cBook;
}