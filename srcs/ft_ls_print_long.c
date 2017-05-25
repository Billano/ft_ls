/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_print_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:58:30 by eurodrig          #+#    #+#             */
/*   Updated: 2017/05/23 22:09:51 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void ft_ls_print_long(t_avl_tree_ls *root, t_ls_permisions *ls_p)
{
	char *link;
	int n;

	link = ft_strnew(PATH_MAX);
	ft_printf("%*s ", ls_p->permission_len, root->permission);
	ft_printf("%*s ", ls_p->link_num_len, root->link_num);
	ft_printf("%-*s  ", ls_p->owner_name_len, root->owner_name);
	ft_printf("%-*s  ", ls_p->group_name_len, root->group_name);
	ft_printf("%*s ", ls_p->size_len, root->size);
	ft_printf("%.12s ", (ctime(&(root->f_stat.st_mtime)) + 4));
	ft_printf("%s", root->d_name);
	if (root->permission[0] == 'l')
	{
		n = readlink(root->path, link, PATH_MAX);
		ft_printf(" -> %s", link);
	}
	ft_putchar('\n');
}
