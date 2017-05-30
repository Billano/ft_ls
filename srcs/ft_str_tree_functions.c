/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tree_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 00:43:33 by eurodrig          #+#    #+#             */
/*   Updated: 2017/05/29 01:01:16 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_str_tree *ft_str_tree_create(char *data)
{
	t_str_tree *root;

	root = 0;
	if (!(root = (t_str_tree *)malloc(sizeof(t_str_tree))))
		return (0);
	root->data = ft_strdup(data);
	root->right = 0;
	root->left = 0;
	return (root);
}

t_str_tree *ft_str_tree_insert(t_str_tree *root, char *data)
{
	if (!root)
		root = ft_str_tree_create(data);
	else if (ft_strcmp(data, root->data) > 0)
		root->right = ft_str_tree_insert(root->right, data);
	else
		root->left = ft_str_tree_insert(root->left, data);
	return (root);
}

t_str_tree *ft_str_tree_min(t_str_tree *root)
{
	if (!root)
		return (0);
	if (!root->left)
		return (root);
	return (root->left);
}

void ft_print_e_files(t_str_tree *root)
{
	if (root)
	{
		ft_print_e_files(root->left);
		ft_print_file_not_found(root->data);
		ft_print_e_files(root->right);
	}
}


void ft_print_reglk_files(t_str_tree *root, t_ls_flags flags, t_ls_permisions *ls_p)
{
	t_ls_data *ls_data;
	char *d_name;
	t_avl_tree_ls *p_long;
	struct stat buff;

	ls_data = 0;
	d_name = 0;
	p_long = 0;
	if (root)
	{
		ft_print_reglk_files(root->left, flags, ls_p);
		if (ft_is_a_reg_file(root->data) || ft_is_link(root->data))
		{
			if (flags.l_flag)
			{
				d_name = root->data; //ft_ls_extract_name(root->data);
				lstat(root->data, &buff);
				ls_data = ft_ls_data_init(d_name, buff, root->data);
				p_long = ft_avl_tree_ls_create(ls_data);
			}
		}
			flags.l_flag ? ft_ls_print_long(p_long, ls_p) : ft_printf("%s\n", root->data);
		ft_print_reglk_files(root->right, flags, ls_p);
	}
}

void ft_print_open_dir(t_str_tree *root, t_ls_flags flags, char *str)
{
	if (root)
	{
		ft_print_open_dir(root->left, flags, str);
		if (ft_strcmp(str, root->data) || root->left)
			ft_putchar('\n');
		if (ft_is_a_dir(root->data))
			ft_printf("%s:\n", root->data);
		ft_open_dir(root->data, flags);
		ft_print_open_dir(root->right, flags, str);
	}
}
