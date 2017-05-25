/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 22:43:02 by eurodrig          #+#    #+#             */
/*   Updated: 2017/05/22 23:12:52 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_ls_data *ft_ls_data_init(struct dirent *f_dir, struct stat f_stat, char *path)
{
	t_ls_data *ls_data;

	ls_data = 0;
	if (!(ls_data = (t_ls_data *)malloc(sizeof(t_ls_data))))
		return (0);
	ls_data->f_dir = f_dir;
	ls_data->f_stat = f_stat;
	ls_data->path = path;
	return (ls_data);
}
