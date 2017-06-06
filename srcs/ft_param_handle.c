/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 19:13:01 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/06 02:30:26 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_param_handle(char **av, int i, t_ls_flags flags)
{
	t_str_tree		*e_files;
	t_str_tree		*dir_files;
	t_str_tree		*other_files;
	t_ls_permisions	*ls_p;

	ls_p = 0;
	e_files = 0;
	dir_files = 0;
	other_files = 0;
	e_files = ft_folder_validator(i, av);
	ft_print_e_files(e_files);
	ft_store_dir_files(av, i, flags, &dir_files);
	ft_store_other_files(av, i, flags, &other_files);
	ls_p = ft_permission_init();
	flags.r_flag ? ft_print_other_files_r(other_files, flags, ls_p) :\
	ft_print_other_files(other_files, flags, ls_p);
	if (dir_files)
		ft_print_dir_files(dir_files, e_files, other_files, flags);
	if (!av[i] && av[i - 1][0] == '-' && !e_files && !dir_files && !other_files)
		ft_open_dir(".", flags);
}
