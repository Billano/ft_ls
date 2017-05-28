/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:43:32 by eurodrig          #+#    #+#             */
/*   Updated: 2016/12/06 18:29:35 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp1;
	t_list	*head;

	head = NULL;
	tmp1 = NULL;
	if (!lst || !f)
		return (NULL);
	if ((head = (*f)(ft_lstnew(lst->content, lst->content_size))))
	{
		tmp1 = head;
		lst = lst->next;
		while (lst)
		{
			tmp1->next = (*f)(ft_lstnew(lst->content, lst->content_size));
			tmp1 = tmp1->next;
			lst = lst->next;
		}
	}
	return (head);
}
