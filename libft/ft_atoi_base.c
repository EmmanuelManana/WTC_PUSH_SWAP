/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 10:42:19 by emanana           #+#    #+#             */
/*   Updated: 2019/08/16 10:42:30 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_valid(char c, int baselen)
{
	if (ft_isdigit(c))
		return (c - '0' < baselen);
	if (ft_islower(c))
		return (c - 'a' + 10 < baselen);
	if (ft_isupper(c))
		return (c - 'A' + 10 < baselen);
	return (0);
}

static int	get_value(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	if (ft_islower(c))
		return (c - 'a' + 10);
	return (c - 'A' + 10);
}

int			ft_atoi_base(const char *str, char *base)
{
	int		sum;
	int		i;
	int		neg;
	int		baselen;

	if (!*str || (baselen = ft_checkbase(base)) == 0)
		return (0);
	i = 0;
	neg = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg = 1;
	sum = 0;
	while (is_valid(str[i], baselen))
	{
		sum *= baselen;
		sum += get_value(str[i]);
		i++;
	}
	return (neg ? -sum : sum);
}
