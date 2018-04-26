/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findShifted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:49:51 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/26 14:54:23 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int search(int *rocks, int left, int right, int value)
{
	int mid = left + (right - left) / 2;

	if (left > right)
		return -1;
	if (rocks[mid] == value)
		return mid;
	if (rocks[left] <= rocks[mid])
	{
		if (rocks[left] <= value && value <= rocks[mid])
			return search(rocks, left, mid - 1, value);
		else
			return search(rocks, mid + 1, right, value);
	}
	else
	{
		if (rocks[mid] <= value && value <= rocks[right])
			return search(rocks, mid + 1, right, value);
		else
			return search(rocks, left, mid - 1, value);
	}
}

int searchShifted(int *rocks, int length, int value)
{
	int start = search(rocks, 0, length - 1, value);
	while (start >= 0 && rocks[start] == value)
		start--;
	return start + 1;
}
