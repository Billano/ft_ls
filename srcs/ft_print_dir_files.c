/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dir_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 16:09:15 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/05 23:19:15 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_print_dir_files(t_str_tree *dir_files, t_str_tree *e_files,\
	t_str_tree *other_files, t_ls_flags flags)
{
	t_str_tree *min;

	min = 0;
	if (!dir_files->left && !dir_files->right && !e_files && !other_files)
		ft_open_dir(dir_files->data, flags);
	else if (other_files)
		ft_print_open_dir_b(dir_files, flags);
	else
	{
		min = ft_str_tree_min(dir_files);
		ft_print_open_dir(dir_files, flags, min->data);
	}
}
