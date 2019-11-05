/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:04:29 by emanana           #+#    #+#             */
/*   Updated: 2019/08/19 10:18:47 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			ft_putnbr_nl(int nbr)
{
	ft_putstr("  ");
	ft_putnbr(nbr);
	ft_putchar('\n');
}

static void			color_print_a(int nbr)
{
	ft_putstr(CYAN);
	ft_putnbr(nbr);
	ft_putstr(RESET);
}

static void			color_print_b(int c_number)
{
	ft_putstr(MAGENTA);
	ft_putstr("  ");
	ft_putnbr(c_number);
	ft_putchar('\n');
	ft_putstr(RESET);
}

void				print(t_stack *stack_a, t_stack *stack_b, int flag)
{
	while (stack_a || stack_b)
	{
		if (flag)
		{
			stack_a ? color_print_a(stack_a->num) :
				ft_putstr(" ");
			stack_b ? color_print_b(stack_b->num) :
				ft_putstr(" \n");
		}
		else
		{
			stack_a ? ft_putnbr(stack_a->num) : ft_putstr("  ");
			stack_b ? ft_putnbr_nl(stack_b->num) : ft_putstr(" \n");
		}
		if (stack_a)
			stack_a = stack_a->next;
		if (stack_b)
			stack_b = stack_b->next;
	}
	ft_putstr("\n");
}
