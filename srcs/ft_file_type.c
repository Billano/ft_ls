/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 00:23:11 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/02 00:24:11 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	ft_file_type(t_ls_data *ls_data)
{
	if (S_ISDIR(ls_data->f_stat.st_mode))
		return ('d');
	else if (S_ISREG(ls_data->f_stat.st_mode))
		return ('-');
	else if (S_ISLNK(ls_data->f_stat.st_mode))
		return ('l');
	else if (S_ISCHR(ls_data->f_stat.st_mode))
		return ('c');
	else if (S_ISBLK(ls_data->f_stat.st_mode))
		return ('b');
	else if (S_ISFIFO(ls_data->f_stat.st_mode))
		return ('p');
	else if (S_ISSOCK(ls_data->f_stat.st_mode))
		return ('s');
	else
		return ('?');
}
