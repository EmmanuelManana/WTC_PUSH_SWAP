/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:58:25 by emanana           #+#    #+#             */
/*   Updated: 2019/11/05 12:48:56 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ko_exit(void)
{
	ko();
	exit(1);
}

long	ft_atoi_l(const char *str)
{
	long	sum;
	int		i;
	int		neg;

	if (!str || !*str)
		return (0);
	i = 0;
	neg = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg = 1;
	sum = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum *= 10;
		sum += str[i] - '0';
		i++;
	}
	return (neg ? -sum : sum);
}

void	error_free(void *p)
{
	free(p);
	error();
}

void	copy_reverse(t_stack **a)
{
	t_stack	*tmp;

	tmp = NULL;
	while (*a)
		push(&tmp, pop(a));
	*a = tmp;
}
