/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_includes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 19:44:13 by eurodrig          #+#    #+#             */
/*   Updated: 2016/12/29 19:44:15 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lst_includes(t_lst *lst, char c)
{
	t_lst		*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->data == c)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
