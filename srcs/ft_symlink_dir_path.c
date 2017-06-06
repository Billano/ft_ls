/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_symlink_dir_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 03:11:22 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/06 03:12:27 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char *ft_symlink_dir_path(char *path)
{
	char			*link;


	link = ft_strnew(PATH_MAX);
	readlink(path, link, PATH_MAX);
	return (link);
}
