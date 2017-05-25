/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstniter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 21:55:39 by eurodrig          #+#    #+#             */
/*   Updated: 2016/12/06 22:02:42 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstniter(t_list *lst, void (*f)(t_list *elem), size_t n)
{
	t_list *tmp;
	size_t i;

	tmp = lst;
	i = 0;
	while ((tmp != NULL) && (i < n))
	{
		(*f)(tmp);
		tmp = tmp->next;
		i--;
	}
}
