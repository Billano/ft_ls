/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:12:05 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/10 17:12:07 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_n	*ft_create_elem_n(int data)
{
	t_list_n *lst;

	lst = NULL;
	if (!(lst = (t_list_n *)malloc(sizeof(t_list_n))))
		return (NULL);
	lst->data = data;
	lst->next = NULL;
	return (lst);
}

t_list_s	*ft_create_elem_s(char *data)
{
	t_list_s *lst;

	lst = NULL;
	if (!(lst = (t_list_s *)malloc(sizeof(t_list_s))))
		return (NULL);
	lst->data = data;
	lst->next = NULL;
	return (lst);
}

t_list_a	*ft_create_elem(void *data)
{
	t_list_a *lst;

	lst = NULL;
	if (!(lst = (t_list_a *)malloc(sizeof(t_list_a))))
		return (NULL);
	lst->data = data;
	lst->next = NULL;
	return (lst);
}
