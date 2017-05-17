/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:23:31 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/10 17:23:32 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_reverse(t_list_a **begin_list)
{
	t_list_a *next;
	t_list_a *prev;
	t_list_a *curr;

	curr = *begin_list;
	next = NULL;
	prev = NULL;
	while (curr)
	{
		next = (curr)->next;
		(curr)->next = prev;
		prev = curr;
		curr = next;
	}
	*begin_list = prev;
}
