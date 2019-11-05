/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:11:38 by emanana           #+#    #+#             */
/*   Updated: 2019/08/16 13:11:40 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*h;
	char	*n;

	if (*needle == 0)
		return ((char *)haystack);
	n = (char *)needle;
	while (*haystack)
	{
		h = (char *)haystack;
		while (*haystack && *haystack && *haystack == *needle)
		{
			haystack++;
			needle++;
		}
		if (!*needle)
			return (h);
		haystack = ++h;
		needle = n;
	}
	return (NULL);
}
