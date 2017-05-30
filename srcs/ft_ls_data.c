/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 22:43:02 by eurodrig          #+#    #+#             */
/*   Updated: 2017/05/28 00:38:35 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_ls_data *ft_ls_data_init(char *d_name, struct stat f_stat, char *path)
{
	t_ls_data *ls_data;

	ls_data = 0;
	if (!(ls_data = (t_ls_data *)malloc(sizeof(t_ls_data))))
		return (0);
	ls_data->d_name = ft_strdup(d_name);
	ls_data->f_stat = f_stat;
	ls_data->path = path;
	return (ls_data);
}
