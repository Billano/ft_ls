/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_other_files.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 01:26:36 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/07 03:02:44 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_print_other_files_helper(t_str_tree *root, t_ls_flags flags,\
	t_ls_permisions *ls_p)
{
	struct stat		buf;
	t_avl_tree_ls	*node;
	t_ls_data		*ls_data;
	char			*link;

	ls_data = 0;
	node = 0;
	if (flags.l_flag)
	{
		lstat(root->data, &buf);
		ls_data = ft_ls_data_init(root->data, buf, root->data);
		ft_ls_print_long(ft_avl_tree_ls_create(ls_data), ls_p, flags);
	}
	else
	{
		if (ft_is_link(root->data))
		{
			link = ft_strnew(PATH_MAX);
			readlink(root->data, link, PATH_MAX);
			ft_is_dir(link) ? ft_open_dir(link, flags) :\
			ft_printf("%s\n", root->data);
		}
		else
			ft_printf("%s\n", root->data);
	}
}

void		ft_print_other_files(t_str_tree *root, t_ls_flags flags,\
	t_ls_permisions *ls_p)
{
	if (root)
	{
		ft_print_other_files(root->left, flags, ls_p);
		ft_print_other_files_helper(root, flags, ls_p);
		ft_print_other_files(root->right, flags, ls_p);
	}
}

void		ft_print_other_files_r(t_str_tree *root, t_ls_flags flags,\
	t_ls_permisions *ls_p)
{
	if (root)
	{
		ft_print_other_files_r(root->right, flags, ls_p);
		ft_print_other_files_helper(root, flags, ls_p);
		ft_print_other_files_r(root->left, flags, ls_p);
	}
}
