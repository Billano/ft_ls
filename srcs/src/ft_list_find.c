/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:20:07 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/10 17:20:09 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_a	*ft_list_find(t_list_a *begin_list, \
	void *data_ref, int (*cmp)())
{
	t_list_a *head;

	head = begin_list;
	while (head->next)
	{
		if ((*cmp)(head->data, data_ref) == 0)
			return (head);
		head = head->next;
	}
	return (NULL);
}
