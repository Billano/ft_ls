/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:21:46 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/10 17:21:48 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_foreach(t_list_a *begin_list, void (*f)(void *))
{
	t_list_a *head;

	head = begin_list;
	while (head)
	{
		(*f)(head->data);
		head = head->next;
	}
}
