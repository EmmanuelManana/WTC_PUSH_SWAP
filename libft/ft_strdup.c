/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 12:50:31 by emanana           #+#    #+#             */
/*   Updated: 2019/08/16 12:50:34 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*d;

	d = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (d == NULL)
		return (NULL);
	return (ft_strcpy(d, s1));
}
