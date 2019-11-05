/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 12:56:22 by emanana           #+#    #+#             */
/*   Updated: 2019/08/16 12:56:24 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	int		i;

	if (!s || !f)
		return (NULL);
	if ((ret = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	if (!s || !f)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		ret[i] = (*f)(i, *(s + i));
		i++;
	}
	return (ret);
}
