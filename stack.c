/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 10:31:10 by emanana           #+#    #+#             */
/*   Updated: 2019/08/19 09:34:57 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create(int n)
{
	t_stack	*ret;

	ret = malloc(sizeof(t_stack));
	ret->num = n;
	ret->next = NULL;
	return (ret);
}

void	push(t_stack **s, int n)
{
	t_stack	*new;
	t_stack	*p;

	p = *s;
	new = create(n);
	*s = new;
	new->next = p;
}

int		pop(t_stack **s)
{
	t_stack	*p;
	int		n;

	if (!*s)
		ko_exit();
	n = (*s)->num;
	p = *s;
	*s = (*s)->next;
	free(p);
	return (n);
}

void	destroy(t_stack **s)
{
	t_stack	*next;

	while (*s)
	{
		next = (*s)->next;
		free(*s);
		*s = next;
	}
	*s = NULL;
}

int		size(t_stack *s)
{
	int count;

	count = 0;
	while (s)
	{
		count++;
		s = s->next;
	}
	return (count);
}
