/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:23:13 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/10 17:23:14 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_remove_if(t_list_a **begin_list, void *data_ref, int (*cmp)())
{
	t_list_a *curr;
	t_list_a *prev;
	t_list_a *next;

	curr = *begin_list;
	prev = NULL;
	next = NULL;
	while (curr)
	{
		next = curr->next;
		if ((*cmp)(curr->data, data_ref) == 0)
		{
			if (*begin_list == curr)
				*begin_list = next;
			else
				prev->next = next;
			free(curr);
			curr = NULL;
		}
		if (curr)
			prev = curr;
		curr = next;
	}
}
