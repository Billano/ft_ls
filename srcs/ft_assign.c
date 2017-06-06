/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 22:17:01 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/05 22:18:02 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	ft_assign_own_ex_p(t_ls_data *ls_data)
{
	if (!(ls_data->f_stat.st_mode & S_IXUSR) &&\
	(ls_data->f_stat.st_mode & S_ISUID))
		return ('S');
	else if ((ls_data->f_stat.st_mode & S_IXUSR) &&\
	(ls_data->f_stat.st_mode & S_ISUID))
		return ('s');
	else if ((ls_data->f_stat.st_mode & S_IXUSR))
		return ('x');
	else
		return ('-');
}

char	ft_assign_group_ex_p(t_ls_data *ls_data)
{
	if (!(ls_data->f_stat.st_mode & S_IXGRP) &&\
	(ls_data->f_stat.st_mode & S_ISGID))
		return ('S');
	else if ((ls_data->f_stat.st_mode & S_IXGRP) &&\
	(ls_data->f_stat.st_mode & S_ISGID))
		return ('s');
	else if ((ls_data->f_stat.st_mode & S_IXGRP))
		return ('x');
	else
		return ('-');
}

char	ft_assign_other_ex_p(t_ls_data *ls_data)
{
	if (ft_is_dir(ls_data->path) &&\
	!(ls_data->f_stat.st_mode & S_IXOTH) && (ls_data->f_stat.st_mode & S_ISVTX))
		return ('T');
	else if (ft_is_dir(ls_data->path) &&\
	(ls_data->f_stat.st_mode & S_IXOTH) && (ls_data->f_stat.st_mode & S_ISVTX))
		return ('t');
	else if ((ls_data->f_stat.st_mode & S_IXOTH))
		return ('x');
	else
		return ('-');
}
