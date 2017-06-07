/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_other_files.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 00:18:50 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/07 00:12:36 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_store_other_files(char **av, int i, t_ls_flags flags,\
	t_str_tree **other_files)
{
	while (av[i])
	{
		if (ft_is_block_file(av[i]) || ft_is_char_file(av[i]) ||\
		(ft_is_link(av[i]) && !ft_is_symlink_dir(av[i])) ||\
		ft_is_socket(av[i]) || ft_is_fifo(av[i]) || ft_is_reg_file(av[i]))
			*other_files =/* ft_str_tree_ls_insert(*other_files, av[i]);*/ flags.t_flag ? ft_str_tree_insert(*other_files,\
				av[i]) : ft_str_tree_insert(*other_files, av[i]);
		i++;
	}
}
