/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permissions_update.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 22:13:28 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/05 22:14:27 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_permissions_update(t_avl_tree_ls *root, t_ls_permisions *ls_p)
{
	ls_p->blocks += root->blocks;
	if (ls_p->permission_len < ft_strlen(root->permission))
		ls_p->permission_len = ft_strlen(root->permission);
	if (ls_p->link_num_len < ft_strlen(root->link_num))
		ls_p->link_num_len = ft_strlen(root->link_num);
	if (ls_p->owner_name_len < ft_strlen(root->owner_name))
		ls_p->owner_name_len = ft_strlen(root->owner_name);
	if (ls_p->group_name_len < ft_strlen(root->group_name))
		ls_p->group_name_len = ft_strlen(root->group_name);
	if (ls_p->size_len < ft_strlen(root->size))
		ls_p->size_len = ft_strlen(root->size);
}
