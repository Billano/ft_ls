/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:22:46 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/10 17:22:48 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back_n(t_list_n **begin_list, int data)
{
	t_list_n *head;

	if (!(*begin_list))
	{
		*begin_list = ft_create_elem_n(data);
	}
	else
	{
		head = *begin_list;
		while (head->next)
			head = head->next;
		head->next = ft_create_elem_n(data);
	}
}

void	ft_list_push_back_s(t_list_s **begin_list, char *data)
{
	t_list_s *head;

	if (!(*begin_list))
	{
		*begin_list = ft_create_elem_s(data);
	}
	else
	{
		head = *begin_list;
		while (head->next)
			head = head->next;
		head->next = ft_create_elem_s(data);
	}
}

void	ft_list_push_back(t_list_a **begin_list, void *data)
{
	t_list_a *head;

	if (!(*begin_list))
	{
		*begin_list = ft_create_elem(data);
	}
	else
	{
		head = *begin_list;
		while (head->next)
			head = head->next;
		head->next = ft_create_elem(data);
	}
}
