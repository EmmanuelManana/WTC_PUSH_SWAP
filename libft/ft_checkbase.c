/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 10:43:51 by emanana           #+#    #+#             */
/*   Updated: 2019/08/16 10:56:43 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkbase(char *base)
{
	int i;

	if (base == NULL || *base == 0 || !base[1])
		return (0);
	i = 1;
	while ((base[i]))
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] - base[i - 1] != 1)
			if (!(ft_isdigit(base[i - 1])
				&& (base[i] == 'a' || base[i] == 'A')))
				return (0);
		i++;
	}
	if (base[i])
		return (0);
	return (i);
}
