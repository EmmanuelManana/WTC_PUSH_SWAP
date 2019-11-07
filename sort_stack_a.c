/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 09:19:35 by emanana           #+#    #+#             */
/*   Updated: 2019/08/19 10:24:06 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_a_three(t_stack **a, t_stack **b, int *nums, int *flags)
{
	if (nums[0])
		a_mult(a, b, (char *[]){"rra", "sa", NULL}, flags);
	if (nums[1])
		apply_inst((t_stack **[]){a, b}, "sa", flags, 1);
	if (nums[2])
		apply_inst((t_stack **[]){a, b}, "rra", flags, 1);
	if (nums[3])
		apply_inst((t_stack **[]){a, b}, "ra", flags, 1);
	if (nums[4])
		a_mult(a, b, (char *[]){"sa", "rra", NULL}, flags);
}

void	sort_a_gt_three(t_stack **a, t_stack **b, int *nums, int *flags)
{
	if (nums[0])
		a_mult(a, b, (char *[]){"ra", "sa", "rra", NULL}, flags);
	else if (nums[1])
		apply_inst((t_stack **[]){a, b}, "sa", flags, 1);
	else if (nums[2])
		a_mult(a, b, (char *[]){"ra", "sa", "rra", "sa", NULL}, flags);
	else if (nums[3])
		a_mult(a, b, (char *[]){"sa", "ra", "sa", "rra", NULL}, flags);
	else if (nums[4])
		a_mult(a, b, (char *[]){"sa", "ra", "sa", "rra", "sa", NULL},
			flags);
}

void	sort_a(t_stack **a, t_stack **b, int *nums, int *flags)
{
	if (size(*a) == 3)
		sort_a_three(a, b, nums, flags);
	else
		sort_a_gt_three(a, b, nums, flags);
}

void	get_bool(t_stack *s, int *nums, int cb)
{
	nums[0] = s->next->num > s->next->next->num && s->next->next->num > s->num;
	nums[1] = s->next->next->num > s->num && s->num > s->next->num;
	nums[2] = s->next->num < s->num && s->num < s->next->next->num;
	nums[3] = s->num > s->next->next->num && s->next->next->num > s->next->num;
	nums[4] = cb
		? s->num < s->next->num && s->next->num < s->next->next->num
		: s->num < s->next->num && s->next->num < s->next->next->num;
}

void	sort_three(t_stack **a, t_stack **b, int *flags, int cb)
{
	t_stack	*s;
	int		nums[5];

	get_bool(s = cb ? *b : *a, nums, cb);
	if (cb)
		sort_b(a, b, nums, flags);
	else
		sort_a(a, b, nums, flags);
}
