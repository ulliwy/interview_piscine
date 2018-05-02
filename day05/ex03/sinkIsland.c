/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinkIsland.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:12:46 by iprokofy          #+#    #+#             */
/*   Updated: 2018/05/01 14:26:57 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

void sinkIsland(int **map, int row, int col)
{
	//printf("row:%d, col: %d \n", row, col);
	if (row >= 0 && col >= 0 && map[row] != NULL && map[row][col] == 1)
	{
		//printf("here\n");
		map[row][col] = 0;
		sinkIsland(map, row - 1, col);
		sinkIsland(map, row + 1, col);
		sinkIsland(map, row, col - 1);
		sinkIsland(map, row, col + 1);
	}
}