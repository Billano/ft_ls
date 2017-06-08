/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_print_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:58:30 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/07 03:16:22 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_ls_print_time(t_avl_tree_ls *root, t_ls_flags flags)
{
	if (flags.bigt_flag)
		ft_printf("%s ", (ctime(&(root->f_stat.st_mtime)) + 4));
	else
	{
		ft_printf("%.6s ", (ctime(&(root->f_stat.st_mtime)) + 4));
		if (ft_time_diff_six(root->f_stat.st_mtime))
			ft_printf(" %.4s ", (ctime(&(root->f_stat.st_mtime)) + 20));
		else
			ft_printf("%.5s ", (ctime(&(root->f_stat.st_mtime)) + 11));
	}
}

void		ft_ls_print_long(t_avl_tree_ls *root, t_ls_permisions *ls_p,\
	t_ls_flags flags)
{
	char	*link;
	int		n;

	link = ft_strnew(PATH_MAX);
	ft_printf("%*s ", ls_p->permission_len, root->permission);
	ft_printf("%*s ", ls_p->link_num_len, root->link_num);
	ft_printf("%-*s  ", ls_p->owner_name_len, root->owner_name);
	if (!flags.o_flag)
		ft_printf("%-*s  ", ls_p->group_name_len, root->group_name);
	ft_printf("%*s ", ls_p->size_len, root->size);
	ft_ls_print_time(root, flags);
	ft_printf("%s", root->d_name);
	if (root->permission[0] == 'l')
	{
		n = readlink(root->path, link, PATH_MAX);
		ft_printf(" -> %s", link);
	}
	ft_putchar('\n');
}
