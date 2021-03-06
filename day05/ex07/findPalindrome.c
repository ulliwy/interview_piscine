/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPalindrome.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 21:33:36 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/05/02 00:40:21 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

int recurse(char *str, int start, int end, int nDelete)
{
	while (end - start > nDelete && str[start] == str[end] && start++ < end--) {}
	if (start > end) return (!nDelete);
	if (nDelete) {
		if (recurse(str, start + 1, end, nDelete - 1)) return str[start] = '\t';
		if (recurse(str, start, end - 1, nDelete - 1)) return str[end] = '\t';
	}
	return start == end;
}

char *findPalindrome(char *sequence, int nDelete)
{
	if (recurse(sequence, 0, strlen(sequence) - 1, nDelete)) {
		char *new = calloc(1, strlen(sequence) - nDelete + 1);
		for (int i = 0, j = 0; i < (int)strlen(sequence); i++) {
			if (sequence[i] == '\t') continue;
			new[j++] = sequence[i];
		}
		return new;
	}
	return NULL;
}
