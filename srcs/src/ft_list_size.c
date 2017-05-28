/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:23:42 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/10 17:23:43 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_list_size_n(t_list_n *begin_list)
{
	t_list_n	*head;
	int			n;

	n = 0;
	head = begin_list;
	while (head)
	{
		n++;
		head = head->next;
	}
	return (n);
}

int	ft_list_size_s(t_list_s *begin_list)
{
	t_list_s	*head;
	int			n;

	n = 0;
	head = begin_list;
	while (head)
	{
		n++;
		head = head->next;
	}
	return (n);
}

int	ft_list_size(t_list_a *begin_list)
{
	t_list_a	*head;
	int			n;

	n = 0;
	head = begin_list;
	while (head)
	{
		n++;
		head = head->next;
	}
	return (n);
}
