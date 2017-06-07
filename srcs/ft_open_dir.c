/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 03:58:50 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/06 20:54:38 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_print_dir(t_avl_tree_ls *root, char *path, t_ls_flags flags,\
	t_ls_permisions *ls_p)
{
	if (flags.l_flag && (ls_p->blocks || root))
		ft_printf("total %lld\n", ls_p->blocks);
	flags.r_flag ? ft_avl_tree_ls_backorder(root,\
		path, flags, ls_p) : ft_avl_tree_ls_inorder(root, path, flags, ls_p);
}

void	ft_open_dir(char *path, t_ls_flags flags)
{
	DIR				*fd;
	t_avl_tree_ls	*root;
	t_ls_permisions	*ls_p;

	root = 0;
	ls_p = 0;
	if (ft_strcmp(".", path) && !ft_is_dir(path))
	{
		if (ft_is_symlink_dir(path))
			ft_open_dir(ft_symlink_dir_path(path), flags);
		return ;
	}
	fd = opendir(path);
	if (!fd)
	{
		perror(ft_strjoin("ls: ", path));
		return ;
	}
	ls_p = ft_permission_init();
	root = ft_store_dir(fd, flags, path, ls_p);
	ft_print_dir(root, path, flags, ls_p);
	if (flags.bigr_flag)
		flags.r_flag ? ft_avl_tree_ls_r_backorder(root, path, flags) :\
		ft_avl_tree_ls_r_inorder(root, path, flags);
	closedir(fd);
}
