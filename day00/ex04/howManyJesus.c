/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:23:41 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/24 10:16:44 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int hash(char *input, int start, int end)
{
	int i = start;
	int hash = 0;

	while (i <= end)
	{
		hash += input[i];
		i++;
	}
	return hash;
}

int howManyJesus(char *bible, char *jesus)
{
	int count = 0;
	int j_len = strlen(jesus);
	int j_hash = hash(jesus, 0, j_len - 1);
	int l = 0;
	int r = 0;
	int curr_hash = 0;

	while(*(bible + r) && r < j_len)
	{
		curr_hash += bible[r];
		r++;
	}
	r--;
	while (*(bible + r))
	{
		if (j_hash == curr_hash)
		{	
			if (!strncmp(jesus, bible + l, j_len))
				count++;
			l++;
			r++;
		}
		else
		{
			l++;
			r++;
			curr_hash -= bible[l - 1];
			curr_hash += bible[r];
		}
	}
	return (count);
}

void test()
{
	char *bible = "hellolloello";
	char *jesus = "ello";
	printf("%d \n", howManyJesus(bible, jesus));
}
