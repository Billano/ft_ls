/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_symlink_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 02:42:45 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/06 20:46:25 by eurodrig         ###   ########.fr       */
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
		if (ft_is_dir(link))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
