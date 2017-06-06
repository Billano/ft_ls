/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permission_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 00:26:34 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/02 16:27:44 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_ls_permisions	*ft_permission_init(void)
{
	t_ls_permisions *ls_p;

	ls_p = 0;
	if (!(ls_p = (t_ls_permisions *)malloc(sizeof(t_ls_permisions))))
		return (NULL);
	ls_p->permission_len = 0;
	ls_p->link_num_len = 0;
	ls_p->owner_name_len = 0;
	ls_p->group_name_len = 0;
	ls_p->size_len = 0;
	ls_p->blocks = 0;
	return (ls_p);
}
