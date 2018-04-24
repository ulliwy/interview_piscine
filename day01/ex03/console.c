/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:27:19 by iprokofy          #+#    #+#             */
/*   Updated: 2018/04/24 16:42:13 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

struct s_stack *stackInit(void)
{
	struct s_stack *stack = malloc(sizeof(struct s_stack));
	stack->item = NULL;
	return stack;
}

void push(struct s_stack *stack, char *word)
{
	if (!stack)
		return;
	struct s_item *new = malloc(sizeof(struct s_item));
	new->word = word;
	if (!stack->item)
	{
		new->next = NULL;
		stack->item = new;
		return;
	}
	new->next = stack->item;
	stack->item = new;
}

void *pop(struct s_stack *stack)
{
	if (!stack)
		return NULL;
	if (!stack->item)
		return NULL;

	struct s_item *current = stack->item;
	char *c;
	stack->item = stack->item->next;
	c = current->word;
	free(current);
	return c;
}

char *console(void)
{
	char input[256];
	char *msg = calloc(1, 1000);
	struct s_stack *stack = stackInit();

	while (1)
	{
		printf(":> ");
		scanf("%s\n", input);
		if (scanf("%s\n", input) < 0)
			break;
		push(stack, input);
	}
}