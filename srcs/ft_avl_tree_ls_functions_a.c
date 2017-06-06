/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_tree_ls_functions_a.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 22:42:16 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/06 00:29:40 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ft_avl_tree_ls_inorder(t_avl_tree_ls *root, char *path,\
	t_ls_flags flags, t_ls_permisions *ls_p)
{
	if (root)
	{
		ft_avl_tree_ls_inorder(root->left, path, flags, ls_p);
		flags.l_flag ? ft_ls_print_long(root, ls_p) :\
		ft_printf("%s\n", root->d_name);
		ft_avl_tree_ls_inorder(root->right, path, flags, ls_p);
	}
}

void			ft_avl_tree_ls_backorder(t_avl_tree_ls *root, char *path,\
	t_ls_flags flags, t_ls_permisions *ls_p)
{
	if (root)
	{
		ft_avl_tree_ls_backorder(root->right, path, flags, ls_p);
		flags.l_flag ? ft_ls_print_long(root, ls_p) :\
		ft_printf("%s\n", root->d_name);
		ft_avl_tree_ls_backorder(root->left, path, flags, ls_p);
	}
}

void			ft_avl_tree_ls_r_inorder(t_avl_tree_ls *root, char *path,\
	t_ls_flags flags)
{
	if (root)
	{
		ft_avl_tree_ls_r_inorder(root->left, path, flags);
		if (ft_is_dir(root->path) && ft_strcmp(".", root->d_name) &&\
		ft_strcmp("..", root->d_name))
		{
			ft_printf("\n%s:\n", root->path);
			ft_open_dir(root->path, flags);
		}
		ft_avl_tree_ls_r_inorder(root->right, path, flags);
	}
}

void			ft_avl_tree_ls_r_backorder(t_avl_tree_ls *root, char *path,\
	t_ls_flags flags)
{
	if (root)
	{
		ft_avl_tree_ls_r_backorder(root->right, path, flags);
		if (ft_is_dir(root->path) && ft_strcmp(".", root->d_name) &&\
		ft_strcmp("..", root->d_name))
		{
			ft_printf("\n%s:\n", root->path);
			ft_open_dir(root->path, flags);
		}
		ft_avl_tree_ls_r_backorder(root->left, path, flags);
	}
}
