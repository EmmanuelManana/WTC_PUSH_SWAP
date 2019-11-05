/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 11:14:41 by emanana           #+#    #+#             */
/*   Updated: 2019/08/16 11:14:45 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*ptr;

	if (!lst)
		return (NULL);
	ret = (*f)(lst);
	lst = lst->next;
	ptr = ret;
	while (lst)
	{
		ret->next = (*f)(lst);
		lst = lst->next;
		ret = ret->next;
	}
	return (ptr);
}
