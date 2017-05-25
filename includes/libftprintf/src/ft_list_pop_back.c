/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:22:17 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/10 17:22:19 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_s	*ft_list_pop_back_s(t_list_s **begin_list)
{
	t_list_s *head;
	t_list_s *ret;

	head = *begin_list;
	while ((head->next)->next)
		head = head->next;
	ret = head->next;
	head->next = NULL;
	return (ret);
}

t_list_n	*ft_list_pop_back_n(t_list_n **begin_list)
{
	t_list_n *head;
	t_list_n *ret;

	head = *begin_list;
	while ((head->next)->next)
		head = head->next;
	ret = head->next;
	head->next = NULL;
	return (ret);
}

t_list_a	*ft_list_pop_back(t_list_a **begin_list)
{
	t_list_a *head;
	t_list_a *ret;

	head = *begin_list;
	while ((head->next)->next)
		head = head->next;
	ret = head->next;
	head->next = NULL;
	return (ret);
}
