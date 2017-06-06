/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_folder_validator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:59:09 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/02 16:41:12 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_str_tree	*ft_folder_validator(int i, char **av)
{
	t_str_tree *e_files;

	e_files = 0;
	while (av[i])
	{
		if (!ft_is_dir(av[i]) && !ft_is_reg_file(av[i]) &&\
		!ft_is_link(av[i]) && !ft_is_block_file(av[i]) &&\
		!ft_is_char_file(av[i]) && !ft_is_socket(av[i]) && !ft_is_fifo(av[i]))
			e_files = ft_str_tree_insert(e_files, av[i]);
		i++;
	}
	return (e_files);
}
