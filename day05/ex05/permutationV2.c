/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutationV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:18:10 by iprokofy          #+#    #+#             */
/*   Updated: 2018/05/01 17:03:36 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void permut(char *arr, int start, int end, char *buf)
{
	struct s_dict *dict = dictInit(256);
	//printf("start: %c, %c\n", arr[start], arr[end]);
	if (start == end)
	{
		printf("->%s\n", arr);
		return;
	}
	for (int i = start; i <= end; i++)
	{
		//printf("-%c -%c\n", arr[start], arr[i]);
		//printf("%c\n", *(arr + i));
		if ()
		{
			swap(&arr[i], &arr[start]);
			permut(arr, start + 1, end);
			swap(&arr[i], &arr[start]);
		}
	}
}

void printUniquePermutations(char *str)
{
	if (!str)
		return ;
	char *buf = malloc(strlen(str) + 1);
	//struct s_dict *dict = dictInit(256);
	permut(str, 0, strlen(str) - 1, buf);
}