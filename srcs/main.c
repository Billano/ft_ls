/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 03:13:47 by eurodrig          #+#    #+#             */
/*   Updated: 2017/05/16 22:18:07 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int ft_avl_height(t_avl_tree_ls *node)
{
	if (!node)
		return (0);
	return (node->height);
}

t_avl_tree_ls *ft_avl_tree_ls_create(struct dirent *f_dir, char *path)
{
	t_avl_tree_ls *node;
	char *n_path;

	node = 0;
	if (!(node = (t_avl_tree_ls *)malloc(sizeof(t_avl_tree_ls))))
		return (0);
	n_path =  ft_strjoin(ft_strjoin(path, "/"), f_dir->d_name);
	node->path = n_path;
	lstat(n_path, &(node->f_stat));
	node->d_name = ft_strdup(f_dir->d_name);
	node->d_namlen = f_dir->d_namlen;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return (node);
}

// t_avl_tree_ls *ft_avl_r_rotate(t_avl_tree_ls *node)
// {
// 	t_avl_tree_ls *left;
// 	t_avl_tree_ls *t_3;
//
//
// }

void ft_avl_tree_ls_inorder(t_avl_tree_ls *root, char *path, t_ls_flags flags)
{
	if (root)
	{
		ft_avl_tree_ls_inorder(root->left, path, flags);
		flags.l_flag? printf("long: |%s|\n", root->d_name) : printf("%s\n", root->d_name);
		ft_avl_tree_ls_inorder(root->right, path, flags);
	}
}

void ft_avl_tree_ls_backorder(t_avl_tree_ls *root, char *path, t_ls_flags flags)
{
	if (root)
	{
		ft_avl_tree_ls_backorder(root->right, path, flags);
		flags.l_flag? printf("long: |%s|\n", root->d_name) : printf("%s\n", root->d_name);
		ft_avl_tree_ls_backorder(root->left, path, flags);
	}
}

void ft_avl_tree_ls_r_inorder(t_avl_tree_ls *root, char *path, t_ls_flags flags)
{
	if (root)
	{
		ft_avl_tree_ls_r_inorder(root->left, path, flags);
		if (ft_is_node_a_dir(root) && ft_strcmp(".", root->d_name) && ft_strcmp("..", root->d_name))
		{
			printf("\n%s:\n", root->path);
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
		if (ft_is_node_a_dir(root) && ft_strcmp(".", root->d_name) && ft_strcmp("..", root->d_name))
		{
			printf("\n%s:\n", root->path);
			ft_open_dir(root->path, flags);
		}
		ft_avl_tree_ls_r_backorder(root->left, path, flags);
	}
}

t_avl_tree_ls *ft_avl_tree_ls_insert(t_avl_tree_ls *root, struct dirent *f_dir, char *path)
{
	if (!root)
		return (ft_avl_tree_ls_create(f_dir, path));
	else if (ft_strcmp(root->d_name, f_dir->d_name) >= 0)
		root->left = ft_avl_tree_ls_insert(root->left, f_dir, path);
	else
		root->right = ft_avl_tree_ls_insert(root->right, f_dir, path);
	return (root);
}

t_avl_tree_ls *ft_store_dir(DIR *fd, t_ls_flags flags, char *path)
{
	t_avl_tree_ls *root;
	struct dirent *f_dir;

	f_dir = 0;
	root = 0;
	if (!fd)
		return 0;
	while ((f_dir = readdir(fd)))
	{
		if (flags.a_flag || f_dir->d_name[0] != '.')
			root = flags.t_flag ? ft_avl_tree_ls_insert(root, f_dir, path) : ft_avl_tree_ls_insert(root, f_dir, path);//aqui se guarda por tiempo
	}
	return (root);
}
//
// t_avl_tree_ls *ft_store_dir_time(DIR *fd, t_ls_flags flags)
// {
// 	t_avl_tree_ls *root;
// 	struct dirent *f_dir;
//
// 	f_dir = 0;
// 	root = 0;
// 	if (!fd)
// 		return 0;
// 	while ((f_dir = readdir(fd)))
// 	{
// 		if (!flags.a_flag || f_dir->d_name[0] != '.')
// 			root = ft_avl_tree_ls_insert(root, f_dir);
// 	}
// 	return (root);
// }

int ft_is_a_dir(char *path)
{
	struct stat f_stat;

	if (lstat(path, &f_stat) == -1)
		return (0);
	return (S_ISDIR(f_stat.st_mode) ? 1 : 0);
}

int ft_is_node_a_dir(t_avl_tree_ls *root)
{
	return (S_ISDIR(root->f_stat.st_mode) ? 1 : 0);
}

void ft_open_dir(char *path, t_ls_flags flags)
{
	DIR *fd;
	t_avl_tree_ls *root;

	root = 0;
	fd = 0;
	if (ft_strcmp(".", path) && !ft_is_a_dir(path))
		return ;
	fd = opendir(path);
	root = ft_store_dir(fd, flags, path);
	flags.r_flag ? ft_avl_tree_ls_backorder(root, path, flags) : ft_avl_tree_ls_inorder(root, path, flags);
	if (flags.bigr_flag)
	{
		flags.r_flag ? ft_avl_tree_ls_r_backorder(root, path, flags) : ft_avl_tree_ls_r_inorder(root, path, flags);
	}
	closedir(fd);
}

void ft_ls_print_long(t_avl_tree_ls *root, char *path)
{

}

t_ls_flags ft_ls_flag_parser(char *str)
{
	t_ls_flags flags;

	flags.l_flag = ft_str_includes(str, 'l') ? 1 : 0;
	flags.bigr_flag = ft_str_includes(str, 'R') ? 1 : 0;
	flags.a_flag = ft_str_includes(str, 'a') ? 1 : 0;
	flags.r_flag = ft_str_includes(str, 'r') ? 1 : 0;
	flags.t_flag = ft_str_includes(str, 't') ? 1 : 0;
	return (flags);
}

int main(int ac, char **av)
{
	t_ls_flags flags;
	int i;


	i = 1;
	if (ac > 1 && av[1][0] == '-')
		flags = ft_ls_flag_parser(av[i]);
	else
		flags = ft_ls_flag_parser("");
	// printf("l_flag: %i, bigr_flag: %i, a_flag: %i, r_flag: %i, t_flag: %i\n", flags.l_flag, flags.bigr_flag, flags.a_flag, flags.r_flag, flags.t_flag);
	if (ac > 1)
	{
		i = av[1][0] == '-' ? 2 : 1;
		while (av[i])
		{
			// printf("dir[%d]:%s\n", i, av[i]);
			ft_open_dir(av[i], flags);
			i++;
		}
		if (i == (av[1][0] == '-' ? 2 : 1))
			ft_open_dir(".", flags);
	}
	else
		ft_open_dir(".", flags);
	return (0);
}
