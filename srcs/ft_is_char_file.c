/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_char_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 20:13:30 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/01 20:16:49 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	ft_is_char_file(char *path)
{
	struct stat f_stat;

	if (lstat(path, &f_stat) == -1)
		return (0);
	return (S_ISCHR(f_stat.st_mode) ? 1 : 0);
}
