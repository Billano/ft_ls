/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:17:12 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/10 17:17:14 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_a	*ft_list_at(t_list_a *begin_list, unsigned int nbr)
{
	t_list_a *head;

	head = begin_list;
	while (head && nbr)
	{
		head = head->next;
		nbr--;
	}
	return (head);
}
