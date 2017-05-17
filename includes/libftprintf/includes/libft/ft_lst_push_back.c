/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 19:31:48 by eurodrig          #+#    #+#             */
/*   Updated: 2016/12/29 19:31:51 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_push_back(t_lst **begin_lst, char data)
{
	t_lst	*lst;

	if (*begin_lst == NULL)
	{
		*begin_lst = ft_lst_new(data);
		return ;
	}
	lst = *begin_lst;
	while (lst->next)
		lst = lst->next;
	lst->next = ft_lst_new(data);
}
