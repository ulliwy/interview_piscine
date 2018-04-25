/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NthLastCity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 21:47:18 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/04/24 22:03:34 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

// struct s_city {
// 	char *name;
// 	struct s_city *next;
// };

char *NthLastCity(struct s_city *city, int n)
{
	struct s_city *temp = NULL;
	struct s_city *current = city;
	int shift = -n;

	while (city)
	{
		if (shift >= 0)
		{
			temp = current;
			current = current->next;
		}
		city = city->next;
		shift++;
	}
	if (temp)
		return temp->name;
	else
		return NULL;
}