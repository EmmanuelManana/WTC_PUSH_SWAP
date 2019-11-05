/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:09:11 by emanana           #+#    #+#             */
/*   Updated: 2019/08/16 13:09:13 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;
	size_t	l;

	if (*needle == 0)
		return ((char *)haystack);
	n = (char *)needle;
	while (*haystack && len > 0)
	{
		h = (char *)haystack;
		l = len;
		while (*haystack && *needle && *haystack == *needle && len-- > 0)
		{
			haystack++;
			needle++;
		}
		if (!*needle)
			return (h);
		haystack = ++h;
		needle = n;
		len = --l;
	}
	return (NULL);
}
