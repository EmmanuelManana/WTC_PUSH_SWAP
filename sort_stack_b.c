/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 09:03:42 by emanana           #+#    #+#             */
/*   Updated: 2019/08/19 10:25:02 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_mult(t_stack **a, t_stack **b, char *s[], int *flags)
{
	while (*s)
		apply_inst((t_stack **[]){a, b}, *s++, flags, 1);
}

void	sort_b_three(t_stack **a, t_stack **b, int *nums, int *flags)
{
	if (nums[0])
		apply_inst((t_stack **[]){a, b}, "rb", flags, 1);
	if (nums[1])
		apply_inst((t_stack **[]){a, b}, "rrb", flags, 1);
	if (nums[2])
		apply_inst((t_stack **[]){a, b}, "sb", flags, 1);
	if (nums[3])
		a_mult(a, b, (char *[]){"sb", "rb", NULL}, flags);
	if (nums[4])
		a_mult(a, b, (char *[]){"sb", "rrb", NULL}, flags);
}

void	sort_b_gt_three(t_stack **a, t_stack **b, int *nums, int *flags)
{
	if (nums[0])
		a_mult(a, b, (char *[]){"sb", "rb", "sb", "rrb", NULL}, flags);
	if (nums[1])
		a_mult(a, b, (char *[]){"rb", "sb", "rrb", "sb", NULL}, flags);
	if (nums[2])
		apply_inst((t_stack **[]){a, b}, "sb", flags, 1);
	if (nums[3])
		a_mult(a, b, (char *[]){"rb", "sb", "rrb", NULL}, flags);
	if (nums[4])
		a_mult(a, b, (char *[]){"sb", "rb", "sb", "rrb", "sb", NULL},
			flags);
}

void	sort_b(t_stack **a, t_stack **b, int *nums, int *flags)
{
	if (size(*b) == 3)
		sort_b_three(a, b, nums, flags);
	else
		sort_b_gt_three(a, b, nums, flags);
}
