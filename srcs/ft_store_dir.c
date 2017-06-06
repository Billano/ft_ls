/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 22:52:30 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/05 22:55:30 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_avl_tree_ls	*ft_store_dir(DIR *fd, t_ls_flags flags, char *path,\
	t_ls_permisions *ls_p)
{
	t_avl_tree_ls	*root;
	struct dirent	*f_dir;
	struct stat		f_stat;
	t_ls_data		*ls_data;

	f_dir = 0;
	root = 0;
	ls_data = 0;
	if (!fd)
		return (0);
	while ((f_dir = readdir(fd)))
	{
		if (flags.a_flag || f_dir->d_name[0] != '.')
		{
			if (lstat(ft_strjoin(ft_strjoin(path, "/"),\
			f_dir->d_name), &f_stat) != -1)
			{
				ls_data = ft_ls_data_init(f_dir->d_name, f_stat, path);
				root = flags.t_flag ? ft_avl_tree_ls_time_insert(root,\
					ls_data, ls_p) : ft_avl_tree_ls_insert(root, ls_data, ls_p);
			}
		}
	}
	return (root);
}
