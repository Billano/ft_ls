/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 03:58:50 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/05 19:50:20 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_ls.h"

void ft_avl_tree_ls_inorder(t_avl_tree_ls *root, char *path, t_ls_flags flags, t_ls_permisions *ls_p)
{
	if (root)
	{
		ft_avl_tree_ls_inorder(root->left, path, flags, ls_p);
		flags.l_flag ? ft_ls_print_long(root, ls_p) : ft_printf("%s\n", root->d_name);
		ft_avl_tree_ls_inorder(root->right, path, flags, ls_p);
	}
}

void ft_avl_tree_ls_backorder(t_avl_tree_ls *root, char *path, t_ls_flags flags, t_ls_permisions *ls_p)
{
	if (root)
	{
		ft_avl_tree_ls_backorder(root->right, path, flags, ls_p);
		flags.l_flag ? ft_ls_print_long(root, ls_p) : ft_printf("%s\n", root->d_name);
		ft_avl_tree_ls_backorder(root->left, path, flags, ls_p);
	}
}

void ft_avl_tree_ls_r_inorder(t_avl_tree_ls *root, char *path, t_ls_flags flags)
{
	if (root)
	{
		ft_avl_tree_ls_r_inorder(root->left, path, flags);
		if (ft_is_dir(root->path) && ft_strcmp(".", root->d_name) && ft_strcmp("..", root->d_name))
		{
			ft_printf("\n%s:\n", root->path);
			ft_open_dir(root->path, flags);
		}
		ft_avl_tree_ls_r_inorder(root->right, path, flags);
	}
}

void ft_avl_tree_ls_r_backorder(t_avl_tree_ls *root, char *path, t_ls_flags flags)
{
	if (root)
	{
		ft_avl_tree_ls_r_backorder(root->right, path, flags);
		if (ft_is_dir(root->path) && ft_strcmp(".", root->d_name) && ft_strcmp("..", root->d_name))
		{
			ft_printf("\n%s:\n", root->path);
			ft_open_dir(root->path, flags);
		}
		ft_avl_tree_ls_r_backorder(root->left, path, flags);
	}
}

t_avl_tree_ls *ft_avl_tree_ls_insert(t_avl_tree_ls *root, t_ls_data *ls_data, t_ls_permisions *ls_p)
{
	t_avl_tree_ls *new;

	new = 0;
	if (!root)
	{
		new = ft_avl_tree_ls_create(ls_data);
		ft_permission_update(new, ls_p);
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

int ft_ls_time_compare(t_avl_tree_ls *root, t_ls_data *ls_data)
{
	if (root->f_stat.st_mtimespec.tv_sec < ls_data->f_stat.st_mtimespec.tv_sec)
	{
		return (1);
	}
	if (root->f_stat.st_mtimespec.tv_sec > ls_data->f_stat.st_mtimespec.tv_sec)
	{
		return (0);
	}
	else
	{
		if (root->f_stat.st_mtimespec.tv_nsec < ls_data->f_stat.st_mtimespec.tv_nsec)
		{
			return (1);
		}
		else if (root->f_stat.st_mtimespec.tv_nsec > ls_data->f_stat.st_mtimespec.tv_nsec)
		{
			return (0);
		}
		else
		{
			return (ft_strcmp(root->d_name, ls_data->d_name) >= 0) ? (1) : (0);
		}
	}
}

t_avl_tree_ls *ft_avl_tree_ls_time_insert(t_avl_tree_ls *root, t_ls_data *ls_data, t_ls_permisions *ls_p)
{
	t_avl_tree_ls *new;

	new = 0;
	if (!root)
	{
		new = ft_avl_tree_ls_create(ls_data);
		ft_permission_update(new, ls_p);
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

t_avl_tree_ls *ft_store_dir(DIR *fd, t_ls_flags flags, char *path, t_ls_permisions *ls_p)
{
	t_avl_tree_ls *root;
	struct dirent *f_dir;
	struct stat f_stat;
	t_ls_data *ls_data;

	f_dir = 0;
	root = 0;
	ls_data = 0;
	if (!fd)
		return 0;
	while ((f_dir = readdir(fd)))
	{
		if (flags.a_flag || f_dir->d_name[0] != '.')
		{
			if (lstat(ft_strjoin(ft_strjoin(path, "/"), f_dir->d_name), &f_stat) != -1)
			{
				ls_data = ft_ls_data_init(f_dir->d_name, f_stat, path);
				root = flags.t_flag ? ft_avl_tree_ls_time_insert(root, ls_data, ls_p) : ft_avl_tree_ls_insert(root, ls_data, ls_p);//aqui se guarda por tiempo
			}
		}
	}
	return (root);
}



void ft_open_dir(char *path, t_ls_flags flags)
{
	DIR *fd;
	t_avl_tree_ls *root;
	t_ls_permisions *ls_p;

	root = 0;
	fd = 0;
	ls_p = 0;
	if (ft_strcmp(".", path) && !ft_is_dir(path))
	{
		// ft_print_file_not_found(path);
		return ;
	}
	fd = opendir(path);
	if (!fd)
	{
		perror(ft_strjoin("ls: ", path));
		// printf("./ft_ls: %s: Permission denied\n", path);
		return ;
	}
	ls_p = ft_permission_init();
	root = ft_store_dir(fd, flags, path, ls_p);
	if (flags.l_flag && (ls_p->blocks || root))
		ft_printf("total %lld\n", ls_p->blocks);
	flags.r_flag ? ft_avl_tree_ls_backorder(root, path, flags, ls_p) : ft_avl_tree_ls_inorder(root, path, flags, ls_p);
	if (flags.bigr_flag)
	{
		flags.r_flag ? ft_avl_tree_ls_r_backorder(root, path, flags) : ft_avl_tree_ls_r_inorder(root, path, flags);
	}
	closedir(fd);
}
