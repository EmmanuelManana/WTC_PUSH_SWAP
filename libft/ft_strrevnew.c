/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrevnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:10:15 by emanana           #+#    #+#             */
/*   Updated: 2019/08/16 13:10:18 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrevnew(char *s)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen(s);
	if ((ret = ft_strnew(len)) == NULL)
		return (NULL);
	if (len > 0)
	{
		i = 0;
		len--;
		while (i < len)
		{
			ret[i] = s[len];
			ret[len] = s[i];
			i++;
			len--;
		}
		ret[i] = s[i];
	}
	return (ret);
}
