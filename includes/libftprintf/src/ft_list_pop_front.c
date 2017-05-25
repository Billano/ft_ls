/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:22:32 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/10 17:22:33 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_n	*ft_list_pop_front_n(t_list_n **begin_list)
{
	t_list_n *head;

	head = *begin_list;
	*begin_list = (*begin_list)->next;
	return (head);
}

t_list_a	*ft_list_pop_front(t_list_a **begin_list)
{
	t_list_a *head;

	head = *begin_list;
	*begin_list = (*begin_list)->next;
	return (head);
}
