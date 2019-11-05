/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 18:37:56 by emanana           #+#    #+#             */
/*   Updated: 2019/11/05 12:48:38 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(1);
}

void	win(void)
{
	ft_putendl("OK");
}

void	ko(void)
{
	ft_putendl("KO");
}

int		gt(int a, int b)
{
	return (a > b);
}

int		lt(int a, int b)
{
	return (a < b);
}
