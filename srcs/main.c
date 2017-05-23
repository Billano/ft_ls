/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 03:13:47 by eurodrig          #+#    #+#             */
/*   Updated: 2017/05/23 00:10:50 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_avl_tree_ls *ft_avl_tree_ls_create(t_ls_data *ls_data)
{
	t_avl_tree_ls *node;
	char *n_path;

	node = 0;
	if (!(node = (t_avl_tree_ls *)malloc(sizeof(t_avl_tree_ls))))
		return (0);
	n_path =  ft_strjoin(ft_strjoin(ls_data->path, "/"), ls_data->f_dir->d_name);
	node->path = n_path;
	node->f_stat = ls_data->f_stat;
	node->d_name = ft_strdup(ls_data->f_dir->d_name);
	node->blocks = (long long)ls_data->f_stat.st_blocks;
	// node->file_size_len = f;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void ft_avl_tree_ls_inorder(t_avl_tree_ls *root, char *path, t_ls_flags flags)
{
	if (root)
	{
		ft_avl_tree_ls_inorder(root->left, path, flags);
		flags.l_flag ? ft_ls_print_long(root) : ft_printf("%s\n", root->d_name);
		ft_avl_tree_ls_inorder(root->right, path, flags);
	}
}

void ft_avl_tree_ls_backorder(t_avl_tree_ls *root, char *path, t_ls_flags flags)
{
	if (root)
	{
		ft_avl_tree_ls_backorder(root->right, path, flags);
		flags.l_flag ? ft_ls_print_long(root) : ft_printf("%s\n", root->d_name);
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
		if (ft_is_node_a_dir(root) && ft_strcmp(".", root->d_name) && ft_strcmp("..", root->d_name))
		{
			ft_printf("\n%s:\n", root->path);
			ft_open_dir(root->path, flags);
		}
		ft_avl_tree_ls_r_backorder(root->left, path, flags);
	}
}

t_avl_tree_ls *ft_avl_tree_ls_insert(t_avl_tree_ls *root, t_ls_data *ls_data)
{
	if (!root)
		return (ft_avl_tree_ls_create(ls_data));
	else if (ft_strcmp(root->d_name, ls_data->f_dir->d_name) >= 0)
	{
		root->blocks += (long long)ls_data->f_stat.st_blocks;
		root->left = ft_avl_tree_ls_insert(root->left, ls_data);
	}
	else
	{
		root->blocks += (long long)ls_data->f_stat.st_blocks;
		root->right = ft_avl_tree_ls_insert(root->right, ls_data);
	}
	return (root);
}

t_avl_tree_ls *ft_avl_tree_ls_time_insert(t_avl_tree_ls *root, t_ls_data *ls_data)
{
	if (!root)
		return (ft_avl_tree_ls_create(ls_data));
	else if (root->f_stat.st_mtime < ls_data->f_stat.st_mtime)
	{
		root->blocks += (long long)ls_data->f_stat.st_blocks;
		root->left = ft_avl_tree_ls_time_insert(root->left, ls_data);
	}
	else
	{
		root->blocks += (long long)ls_data->f_stat.st_blocks;
		root->right = ft_avl_tree_ls_time_insert(root->right, ls_data);
	}
	return (root);
}

t_avl_tree_ls *ft_store_dir(DIR *fd, t_ls_flags flags, char *path)
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
				ls_data = ft_ls_data_init(f_dir, f_stat, path);
				root = flags.t_flag ? ft_avl_tree_ls_time_insert(root, ls_data) : ft_avl_tree_ls_insert(root, ls_data);//aqui se guarda por tiempo
			}
		}
	}
	return (root);
}

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
	t_ls_permisions *ls_p;

	root = 0;
	fd = 0;
	ls_p = 0;
	if (ft_strcmp(".", path) && !ft_is_a_dir(path))
	{
		// ft_print_file_not_found(path);
		return ;
	}
	fd = opendir(path);
	if (!fd)
	{
		printf("./ft_ls: %s: Permission denied\n", path);
		return ;
	}
	ls_p = ft_permission_init();
	root = ft_store_dir(fd, flags, path);
	if (flags.l_flag)
		ft_printf("total %lld\n", root->blocks);
	flags.r_flag ? ft_avl_tree_ls_backorder(root, path, flags) : ft_avl_tree_ls_inorder(root, path, flags);
	if (flags.bigr_flag)
	{
		flags.r_flag ? ft_avl_tree_ls_r_backorder(root, path, flags) : ft_avl_tree_ls_r_inorder(root, path, flags);
	}
	closedir(fd);
}

char ft_file_type(t_avl_tree_ls *root)
{
	if (S_ISDIR(root->f_stat.st_mode))
		return ('d');
	else if (S_ISREG(root->f_stat.st_mode))
		return ('-');
	else if (S_ISLNK(root->f_stat.st_mode))
		return ('l');
	else if (S_ISCHR(root->f_stat.st_mode))
		return ('c');
	else if (S_ISBLK(root->f_stat.st_mode))
		return ('b');
	else if (S_ISFIFO(root->f_stat.st_mode))
		return ('p');
	else if (S_ISSOCK(root->f_stat.st_mode))
		return ('s');
	else
		return ('.');
}

char *ft_file_permisions(t_avl_tree_ls *root)
{
	char *str;

	str = ft_strnew(11);
	str[0] = ft_file_type(root);
	str[1] = (root->f_stat.st_mode & S_IRUSR) ? 'r' : '-';
	str[2] = (root->f_stat.st_mode & S_IWUSR) ? 'w' : '-';
	str[3] = (root->f_stat.st_mode & S_IXUSR) ? 'x' : '-';
	str[4] = (root->f_stat.st_mode & S_IRGRP) ? 'r' : '-';
	str[5] = (root->f_stat.st_mode & S_IWGRP) ? 'w' : '-';
	str[6] = (root->f_stat.st_mode & S_IXGRP) ? 'x' : '-';
	str[7] = (root->f_stat.st_mode & S_IROTH) ? 'r' : '-';
	str[8] = (root->f_stat.st_mode & S_IWOTH) ? 'w' : '-';
	str[9] = (root->f_stat.st_mode & S_IXOTH) ? 'x' : '-';
	return (str);
}

void ft_ls_print_long(t_avl_tree_ls *root)
{
	struct passwd *pwd;
	struct group *group;

	pwd = 0;
	pwd = getpwuid(root->f_stat.st_uid);
	group = 0;
	group = getgrgid(root->f_stat.st_gid);
	ft_printf("%s  %ld %s  %s %lld %.12s %s\n", ft_file_permisions(root), (long)root->f_stat.st_nlink, pwd->pw_name, group->gr_name, (long long)root->f_stat.st_size, ctime(&(root->f_stat.st_mtime)) + 4, root->d_name);
}

int main(int ac, char **av)
{
	t_ls_flags flags;
	t_str_tree *e_files;
	int i;

	i = 1;
	e_files = 0;
	flags = ft_flags_init();
	if (!ft_flags_parser(ac, av, &i, &flags))
		return (1);
	if (ac > 1)
	{
		e_files = ft_folder_validator(i, av);
		ft_print_e_files(e_files);
		// i = av[1][0] == '-' ? 2 : 1;
		while (av[i])
		{
			if (ft_is_a_dir(av[i]) && e_files)
				ft_printf("%s:\n", av[i]);
			ft_open_dir(av[i], flags);
			i++;
		}
		if (!av[i] && av[i - 1][0] == '-')
			ft_open_dir(".", flags);
	}
	else
		ft_open_dir(".", flags);
	return (0);
}
