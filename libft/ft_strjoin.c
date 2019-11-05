/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 12:53:07 by emanana           #+#    #+#             */
/*   Updated: 2019/08/16 12:53:21 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		l;

	if (!s1 && !s2)
		return (NULL);
	l = 0;
	if (s1)
		l += ft_strlen(s1);
	if (s2)
		l += ft_strlen(s2);
	if ((ret = ft_strnew(l)) == NULL)
		return (NULL);
	if (s1)
		ft_strcpy(ret, s1);
	if (s2)
		ft_strcat(ret, s2);
	return (ret);
}
