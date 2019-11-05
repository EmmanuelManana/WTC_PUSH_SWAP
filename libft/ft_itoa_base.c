/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 11:03:31 by emanana           #+#    #+#             */
/*   Updated: 2019/08/16 11:04:45 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n, int base)
{
	int i;

	if (n == 0)
		return (1);
	i = 1;
	while (n /= base)
		i++;
	return (i);
}

char			*ft_itoa_base(int n, int base)
{
	char	*ret;
	size_t	len;
	int		mod;
	int		neg;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_numlen(n, base);
	neg = 0;
	if (n < 0)
		neg = 1;
	len += neg;
	if ((ret = ft_memalloc(len + 1)) == NULL)
		return (NULL);
	if (neg)
		ret[0] = '-';
	if (n == 0)
		ret[0] = '0';
	while (n)
	{
		mod = ft_abs(n % base);
		ret[--len] = (mod < 10) ? (mod + '0') : (mod - 10 + 'A');
		n = n / base;
	}
	return (ret);
}
