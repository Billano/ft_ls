/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:23:01 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/10 17:23:03 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_front_s(t_list_s **begin_list, char *data)
{
	t_list_s *node;

	if (!(*begin_list))
		*begin_list = ft_create_elem_s(data);
	else
	{
		node = ft_create_elem_s(data);
		node->next = *begin_list;
		*begin_list = node;
	}
}

void	ft_list_push_front_n(t_list_n **begin_list, int data)
{
	t_list_n *node;

	if (!(*begin_list))
		*begin_list = ft_create_elem_n(data);
	else
	{
		node = ft_create_elem_n(data);
		node->next = *begin_list;
		*begin_list = node;
	}
}

void	ft_list_push_front(t_list_a **begin_list, void *data)
{
	t_list_a *node;

	if (!(*begin_list))
		*begin_list = ft_create_elem(data);
	else
	{
		node = ft_create_elem(data);
		node->next = *begin_list;
		*begin_list = node;
	}
}
