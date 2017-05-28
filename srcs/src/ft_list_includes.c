/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_includes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 05:16:44 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/23 05:16:47 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_includes_s(t_list_s *lst, char *str)
{
	t_list_s		*tmp;

	tmp = lst;
	while (tmp)
	{
		if (ft_strcmp(tmp->data, str) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		ft_list_includes_n(t_list_n *lst, int n)
{
	t_list_n		*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->data == n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
