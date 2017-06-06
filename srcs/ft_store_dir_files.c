/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_dir_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 00:18:03 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/06 02:53:39 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_store_dir_files(char **av, int i, t_ls_flags flags,\
	t_str_tree **dir_files)
{
	while (av[i])
	{
		if (ft_is_dir(av[i]) || ft_is_symlink_dir(av[i]))
			*dir_files = flags.t_flag ? ft_str_tree_insert(*dir_files, av[i]) :\
			ft_str_tree_insert(*dir_files, av[i]);
		i++;
	}
}
