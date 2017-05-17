/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 02:19:14 by eurodrig          #+#    #+#             */
/*   Updated: 2016/12/05 19:28:53 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	tmp = *alst;
	if (!*alst)
		return ;
	while (tmp)
	{
		tmp = (*alst)->next;
		(*del)((*alst)->content, ft_strlen((*alst)->content));
		free(*alst);
		(*alst)->next = NULL;
		(*alst) = tmp;
	}
}
