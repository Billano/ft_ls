/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree_ls_functions_b.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:49:54 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/06 00:30:16 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char		*ft_node_size(char n, t_ls_data *ls_data)
{
	return ((n == 'c') ?\
	ft_strjoin(ft_strjoin(ft_itoa_base(major(ls_data->f_stat.st_rdev), 10),\
	", "), ft_itoa_base(minor(ls_data->f_stat.st_rdev), 10)) :\
	ft_itoa_base((long long)ls_data->f_stat.st_size, 10));
}

t_avl_tree_ls	*ft_avl_tree_ls_create(t_ls_data *ls_data)
{
	t_avl_tree_ls	*node;
	char			*n_path;
	struct passwd	*pwd;
	struct group	*group;

	pwd = getpwuid(ls_data->f_stat.st_uid);
	group = getgrgid(ls_data->f_stat.st_gid);
	if (!(node = (t_avl_tree_ls *)malloc(sizeof(t_avl_tree_ls))))
		return (0);
	if (ft_strcmp(ls_data->path, ls_data->d_name))
		n_path = ft_strjoin(ft_strjoin(ls_data->path, "/"), ls_data->d_name);
	else
		n_path = ls_data->path;
	node->path = n_path;
	node->f_stat = ls_data->f_stat;
	node->d_name = ft_strdup(ls_data->d_name);
	node->blocks = (long long)ls_data->f_stat.st_blocks;
	node->permission = ft_file_permissions(ls_data, n_path);
	node->link_num = ft_itoa_base((long)ls_data->f_stat.st_nlink, 10);
	node->owner_name = ft_strdup(pwd->pw_name);
	node->group_name = ft_strdup(group->gr_name);
	node->size = ft_node_size(node->permission[0], ls_data);
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_avl_tree_ls	*ft_avl_tree_ls_insert(t_avl_tree_ls *root,\
	t_ls_data *ls_data, t_ls_permisions *ls_p)
{
	t_avl_tree_ls *new;

	new = 0;
	if (!root)
	{
		new = ft_avl_tree_ls_create(ls_data);
		ft_permissions_update(new, ls_p);
		return (new);
	}
	else if (ft_strcmp(root->d_name, ls_data->d_name) >= 0)
	{
		root->left = ft_avl_tree_ls_insert(root->left, ls_data, ls_p);
	}
	else
	{
		root->right = ft_avl_tree_ls_insert(root->right, ls_data, ls_p);
	}
	return (root);
}

t_avl_tree_ls	*ft_avl_tree_ls_time_insert(t_avl_tree_ls *root,\
	t_ls_data *ls_data, t_ls_permisions *ls_p)
{
	t_avl_tree_ls *new;

	new = 0;
	if (!root)
	{
		new = ft_avl_tree_ls_create(ls_data);
		ft_permissions_update(new, ls_p);
		return (new);
	}
	else if (ft_ls_time_compare(root, ls_data))
	{
		root->left = ft_avl_tree_ls_time_insert(root->left, ls_data, ls_p);
	}
	else
	{
		root->right = ft_avl_tree_ls_time_insert(root->right, ls_data, ls_p);
	}
	return (root);
}
