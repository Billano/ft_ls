/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_time_compare.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 22:48:57 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/05 22:58:45 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	ft_ls_time_compare(t_avl_tree_ls *root, t_ls_data *ls_data)
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
		if (root->f_stat.st_mtimespec.tv_nsec <\
			ls_data->f_stat.st_mtimespec.tv_nsec)
		{
			return (1);
		}
		else if (root->f_stat.st_mtimespec.tv_nsec >\
			ls_data->f_stat.st_mtimespec.tv_nsec)
		{
			return (0);
		}
		else
		{
			return (ft_strcmp(root->d_name, ls_data->d_name) >= 0) ? (1) : (0);
		}
	}
}
