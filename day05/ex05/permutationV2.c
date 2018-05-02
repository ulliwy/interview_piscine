/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutationV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:18:10 by iprokofy          #+#    #+#             */
/*   Updated: 2018/05/01 20:20:20 by Ulliwy           ###   ########.fr       */
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

void permut(char *arr, int start, int end, struct s_dict *dict)
{
	if (start == end)
	{
		if (dictSearch(dict, arr) == -1)
			printf("%s\n", arr);
		dictInsert(dict, arr, 1);
	}
	for (int i = start; i < end; i++)
	{
		swap(&arr[i], &arr[start]);
		permut(arr, start + 1, end, dict);
		swap(&arr[i], &arr[start]);
	}
}

void printUniquePermutations(char *str)
{
	if (!str)
		return ;
	struct s_dict *dict = dictInit(256);
	permut(str, 0, strlen(str), dict);
}
