/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:18:20 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/10 17:18:23 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_clear(t_list_a **begin_list)
{
	t_list_a *head;

	while (*begin_list)
	{
		head = *begin_list;
		*begin_list = (*begin_list)->next;
		free(head);
		head = 0;
	}
}
