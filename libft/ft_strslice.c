/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strslice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:10:43 by emanana           #+#    #+#             */
/*   Updated: 2019/08/16 13:10:47 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strslice(char const *s, int start, int end)
{
	char	*ret;
	int		len;

	len = end - start;
	if ((ret = ft_strnew(len)) == NULL)
		return (NULL);
	if (start < 0)
	{
		start *= -1;
		return (ft_strsub(&s[ft_strlen(s) - start], 0, len));
	}
	return (ft_strsub(s, start, len));
}
