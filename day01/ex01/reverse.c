/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:14:50 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/25 13:07:29 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void printReverse(struct s_node *lst)
{
	static int i = 0;
	if (!lst)
		return;
	i++;
	printReverse(lst->next);
	i--;
	printf("%s", lst->word);
	if (i)
		printf(" ");
	else
		printf("\n");
}
