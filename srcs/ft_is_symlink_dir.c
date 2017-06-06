/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_symlink_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 02:42:45 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/06 02:56:29 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	ft_is_symlink_dir(char *path)
{
	char			*link;

	if (ft_is_link(path))
	{
		link = ft_strnew(PATH_MAX);
		readlink(path, link, PATH_MAX);
		return ft_is_dir(link) ? (1) : (0);
	}
	else
		return (0);
}
