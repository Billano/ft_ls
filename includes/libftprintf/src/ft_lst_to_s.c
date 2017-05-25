/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 20:34:24 by eurodrig          #+#    #+#             */
/*   Updated: 2016/12/29 20:34:31 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lst_to_s(t_lst *lst)
{
	char		*str;
	size_t		i;
	t_lst		*tmp;
	t_lst		*head;

	tmp = lst;
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * ft_lst_len(tmp) + 1)))
		return (NULL);
	while (tmp)
	{
		str[i++] = tmp->data;
		head = tmp;
		tmp = tmp->next;
		free(head);
	}
	str[i] = '\0';
	return (str);
}
