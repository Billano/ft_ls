/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:21:34 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/10 17:21:36 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_foreach_if(t_list_a *begin_list,\
	void (*f)(void *), void *data_ref, int (*cmp)())
{
	t_list_a *head;

	head = begin_list;
	while (head)
	{
		if ((*cmp)(head->data, data_ref) == 0)
			(*f)(head->data);
		head = head->next;
	}
}
