/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:21:57 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/10 17:21:59 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_s	*ft_list_last_s(t_list_s *begin_list)
{
	t_list_s *head;

	head = begin_list;
	while (head->next)
		head = head->next;
	return (head);
}

t_list_n	*ft_list_last_n(t_list_n *begin_list)
{
	t_list_n *head;

	head = begin_list;
	while (head->next)
		head = head->next;
	return (head);
}

t_list_a	*ft_list_last(t_list_a *begin_list)
{
	t_list_a *head;

	head = begin_list;
	while (head->next)
		head = head->next;
	return (head);
}
