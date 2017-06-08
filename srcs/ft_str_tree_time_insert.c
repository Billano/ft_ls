/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tree_time_insert.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 04:28:29 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/07 22:40:30 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_str_tree	*ft_str_tree_time_insert(t_str_tree *root, char *path)
{
	t_avl_tree_ls	*rroot;
	t_ls_data		*ls_data;
	struct stat		r_stat;
	struct stat		p_stat;

	if (root)
	{
		ls_data = 0;
		lstat(root->data, &r_stat);
		lstat(path, &p_stat);
		ls_data = ft_ls_data_init(root->data, r_stat, root->data);
		rroot = 0;
		rroot = ft_avl_tree_ls_create(ls_data);
		ls_data = ft_ls_data_init(path, p_stat, path);
	}
	if (!root)
	{
		root = ft_str_tree_create(path);
	}
	else if (ft_ls_time_compare(rroot, ls_data))
		root->left = ft_str_tree_time_insert(root->left, path);
	else
		root->right = ft_str_tree_time_insert(root->right, path);
	return (root);
}
