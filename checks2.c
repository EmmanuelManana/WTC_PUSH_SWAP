/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 05:13:24 by emanana           #+#    #+#             */
/*   Updated: 2019/08/19 10:30:11 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_sorted(t_stack *s, int (*cmp)(int, int))
{
	if (!s)
		return (1);
	while (s->next)
	{
		if ((*cmp)(s->num, s->next->num) == 0)
			break ;
		s = s->next;
	}
	return (!s->next);
}

int		check_sorted_upto(t_stack *s, int upto, int (*cmp)(int, int))
{
	if (!s)
		return (upto == 0);
	if (!s->next)
		return (upto == 1);
	while (s->next && --upto)
	{
		if ((*cmp)(s->num, s->next->num) == 0)
			return (0);
		s = s->next;
	}
	return (1);
}

int		check_win(t_stack *a, t_stack *b)
{
	return (check_sorted(a, &lt) && !b);
}

void	check_print(char *str, int *flags, t_stack *stack_a,
								t_stack *stack_b)
{
	if (flags[1])
	{
		ft_putstr(BLUE);
		ft_putstr(str);
		ft_putstr(RESET);
		ft_putstr("\n");
	}
	else
		ft_putendl(str);
	if (flags[0])
		print(stack_a, stack_b, flags[1]);
}
