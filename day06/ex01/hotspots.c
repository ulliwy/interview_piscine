/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotspots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 10:39:16 by iprokofy          #+#    #+#             */
/*   Updated: 2018/05/02 15:46:14 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int selectHotspots(struct s_hotspot **hotspots)
{
	if (!hotspots)
		return 0;
	int count = 0;
	int left = 0;
	for (int i = 1; hotspots[i]; i++)
	{
		if (hotspots[i]->pos + hotspots[i]->radius < hotspots[left]->radius + hotspots[left]->radius)
			left = i;
		else if (hotspots[i]->pos - hotspots[i]->radius >= hotspots[left]->pos + hotspots[left]->radius)
		{
			count++;
			left = i;
		}
	}
	return count + 1;
}
