/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:53:57 by eurodrig          #+#    #+#             */
/*   Updated: 2016/12/06 13:05:07 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint_s(t_list *lst)
{
	t_list *tmp;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp->next)
	{
		ft_putstr((char *)tmp->content);
		tmp = tmp->next;
	}
}
