/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:13:13 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/23 10:34:03 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int  searchPrice(struct s_art **arts, char *name)
{
	int i = 0;

	while (arts[i])
	{
		if (!strcmp(arts[i]->name, name))
			return (arts[i]->price);
		i++;
	}
	return (-1);
}