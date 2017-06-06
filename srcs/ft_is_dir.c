/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 19:22:12 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/01 19:41:04 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	ft_is_dir(char *path)
{
	struct stat f_stat;

	if (lstat(path, &f_stat) == -1)
		return (0);
	return (S_ISDIR(f_stat.st_mode) ? 1 : 0);
}
