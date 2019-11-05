/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 12:53:59 by emanana           #+#    #+#             */
/*   Updated: 2019/08/16 12:54:00 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src,
	size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	bytes;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	bytes = dstsize - dstlen - 1;
	ft_strncat(dst, (char *)src, bytes);
	return (dstlen + srclen);
}
