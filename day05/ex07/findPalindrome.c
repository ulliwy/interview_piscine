/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPalindrome.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 21:33:36 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/05/02 00:02:31 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

static int doMagic(int **pos, int val) {
	**pos = val;
	(*pos)++;
	return 1;
}

int recurse(char *str, int start, int end, int nDelete, int **pos)
{
	while (str[start] == str[end] && start++ < end--) {}
	if (start >= end) return !nDelete;
	if (nDelete) {
		if (recurse(str, start + 1, end, nDelete - 1, pos)) return doMagic(pos, start);
		if (recurse(str, start, end - 1, nDelete - 1, pos)) return doMagic(pos, end);
	}
	return 0;
}

char *findPalindrome(char *sequence, int nDelete)
{
	int pos[nDelete], *p = pos;
	if (recurse(sequence, 0, strlen(sequence) - 1, nDelete, &p)) {
		char *new = calloc(1, strlen(sequence) - nDelete + 1);
		for (int i = 0, j = 0, k = 0; i < (int)strlen(sequence); i++) {
			if (!nDelete || i != pos[k]) new[j++] = sequence[i];
			else k++;
		}
		return new;
	}
	return NULL;
}
