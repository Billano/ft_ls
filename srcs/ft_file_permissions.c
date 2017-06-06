/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_permissions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 22:11:57 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/05 22:20:06 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*ft_file_permissions(t_ls_data *ls_data, char *path)
{
	char *str;

	str = ft_strnew(12);
	str[0] = ft_file_type(ls_data);
	str[1] = (ls_data->f_stat.st_mode & S_IRUSR) ? 'r' : '-';
	str[2] = (ls_data->f_stat.st_mode & S_IWUSR) ? 'w' : '-';
	str[3] = ft_assign_own_ex_p(ls_data);
	str[4] = (ls_data->f_stat.st_mode & S_IRGRP) ? 'r' : '-';
	str[5] = (ls_data->f_stat.st_mode & S_IWGRP) ? 'w' : '-';
	str[6] = ft_assign_group_ex_p(ls_data);
	str[7] = (ls_data->f_stat.st_mode & S_IROTH) ? 'r' : '-';
	str[8] = (ls_data->f_stat.st_mode & S_IWOTH) ? 'w' : '-';
	str[9] = ft_assign_other_ex_p(ls_data);
	str[10] = ft_set_acl(path);
	return (str);
}
