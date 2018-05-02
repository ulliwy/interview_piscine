/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:00:56 by iprokofy          #+#    #+#             */
/*   Updated: 2018/05/01 15:11:03 by iprokofy         ###   ########.fr       */
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

void permut(char *str, int start, int end)
{
	if (start == end)
	{
		printf("%s\n", str);
		return;
	}
	for (int i = start; i <= end; i++)
	{
		swap(&str[start], &str[i]);
		permut(str, start + 1, end);
		swap(&str[i], &str[start]);
	}
}

void printPermutations(char *str)
{
	permut(str, 0, strlen(str) - 1);
}