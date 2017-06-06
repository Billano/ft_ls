/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_open_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 00:43:33 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/06 03:15:53 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_print_open_dir(t_str_tree *root, t_ls_flags flags, char *str)
{
	if (root)
	{
		ft_print_open_dir(root->left, flags, str);
		if (ft_strcmp(str, root->data) || root->left)
			ft_putchar('\n');
		if (ft_is_dir(root->data) || ft_is_symlink_dir(root->data))
			ft_printf("%s:\n", root->data);
		ft_open_dir(root->data, flags);
		ft_print_open_dir(root->right, flags, str);
	}
}

void		ft_print_open_dir_b(t_str_tree *root, t_ls_flags flags)
{
	if (root)
	{
		ft_print_open_dir_b(root->left, flags);
		ft_putchar('\n');
		if (ft_is_dir(root->data) || ft_is_symlink_dir(root->data))
			ft_printf("%s:\n", root->data);
		ft_open_dir(root->data, flags);
		ft_print_open_dir_b(root->right, flags);
	}
}
