/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:12:14 by emanana           #+#    #+#             */
/*   Updated: 2019/08/16 13:12:16 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(char c)
{
	return ((c == '\n' || c == '\t' || c == ' '));
}

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] && ft_is_space(s[start]))
		start++;
	end = ft_strlen(s) - 1;
	while (end > start && ft_is_space(s[end]))
		end--;
	if (end - start == 0)
		return (ft_strdup(s));
	return (ft_strsub(s, start, end - start + 1));
}
