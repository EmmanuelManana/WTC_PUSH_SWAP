/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 09:43:56 by emanana           #+#    #+#             */
/*   Updated: 2019/08/19 10:26:37 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition(t_stack **ss[], int *slens, int *flags, int *mcb)
{
	t_stack **s;
	int		(*cmp)(int, int);
	int		slen;
	int		r;
	int		l;

	r = 0;
	s = mcb[1] ? ss[1] : ss[0];
	slen = mcb[1] ? slens[1] : slens[0];
	cmp = mcb[1] ? &gt : &lt;
	while (slen-- > 0)
	{
		if ((*cmp)((*s)->num, mcb[0]))
			apply_inst(ss, mcb[1] ? "pa" : "pb", flags, 1);
		else
		{
			apply_inst(ss, mcb[1] ? "rb" : "ra", flags, 1);
			r++;
		}
	}
	l = mcb[1] ? size(*ss[1]) : size(*ss[0]);
	if (l > 3 && l != r)
		while (r-- > 0 && !check_sorted_upto(*s, slen, cmp))
			apply_inst(ss, mcb[1] ? "rrb" : "rra", flags, 1);
}

int		glen(int len)
{
	return (len % 2 == 1 ? len / 2 + 1 : len / 2);
}

void	pa(t_stack **a, t_stack **b, int blen, int *flags)
{
	while (blen-- > 0)
		apply_inst((t_stack **[]){a, b}, "pa", flags, 1);
}

void	check_swap(t_stack **a, t_stack **b, int *flags)
{
	if (*a && (*a)->next && (*a)->num > (*a)->next->num)
		apply_inst((t_stack **[]){a, b}, "sa", flags, 1);
	if (*b && (*b)->next && (*b)->num < (*b)->next->num)
		apply_inst((t_stack **[]){a, b}, "sb", flags, 1);
}
