/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correctSong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 21:26:31 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/04/30 21:39:23 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void correctSong(struct s_bit *bit, int l, int row, int col, int dist)
{
	int i = row;
	if (row < bit->n && col < l)
	{
		while (dist && i < bit->n)
		{
			bit->arr[i] = 1 << col;
			i++;
			dist--;
		}
	}
}