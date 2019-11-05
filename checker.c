/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 20:59:27 by emanana           #+#    #+#             */
/*   Updated: 2019/08/19 09:48:47 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stack *a, t_stack *b, int *flags)
{
	ft_putendl("stack_a");
	print(a, b, flags[1]);
}

void	checker(t_stack *a, int *flags)
{
	t_stack	*b;
	char	*inst;

	b = NULL;
	if (flags)
		init(a, b, flags);
	while (get_next_line(STDIN_FILENO, &inst) == 1)
	{
		if (check_inst(inst))
		{
			apply_inst((t_stack **[]){&a, &b}, inst, flags, 0);
			free(inst);
			if (flags[0])
				print(a, b, flags[1]);
		}
		else
			error();
	}
	if (check_win(a, b))
		win();
	else
		ko();
	destroy(&a);
	destroy(&b);
}

int		main(int ac, char **av)
{
	return (process_cmd(ac, av, &checker));
}
