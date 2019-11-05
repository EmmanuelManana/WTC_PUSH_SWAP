/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 12:54:47 by emanana           #+#    #+#             */
/*   Updated: 2019/08/16 12:54:48 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		i;

	if (!s || !f)
		return (NULL);
	if ((ret = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		ret[i] = (*f)(*(s + i));
		i++;
	}
	return (ret);
}
