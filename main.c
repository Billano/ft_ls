/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 03:13:47 by eurodrig          #+#    #+#             */
/*   Updated: 2017/05/27 21:23:16 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_ls.h"

int main(int ac, char **av)
{
	t_ls_flags flags;
	t_str_tree *e_files;
	t_str_tree *rl_files;
	t_str_tree *dir_files;
	t_str_tree *min;
	t_ls_permisions *ls_p;
	int i;

	i = 1;
	e_files = 0;
	rl_files = 0;
	dir_files = 0;
	min = 0;
	ls_p = 0;
	flags = ft_flags_init();
	if (!ft_flags_parser(ac, av, &i, &flags))
		return (1);
	if (ac > 1)
	{
		e_files = ft_folder_validator(i, av);
		ft_print_e_files(e_files);
		// i = av[1][0] == '-' ? 2 : 1;
		while (av[i])
		{
			// if (ft_is_a_dir(av[i]) && e_files)
			// 	ft_printf("%s:\n", av[i]);
			// if (ft_is_a_reg_file(av[i]))
			// 	ft_printf("%s\n", av[i]);
			if (ft_is_a_dir(av[i]))
				dir_files = ft_str_tree_insert(dir_files, av[i]);
			else if (ft_is_a_reg_file(av[i]) || ft_is_link(av[i]))
				rl_files = ft_str_tree_insert(rl_files, av[i]);

			// ft_open_dir(av[i], flags);
			i++;
		}
		min = (e_files || rl_files) ? 0 : ft_str_tree_min(dir_files);
		ls_p = ft_permission_init();
		ft_print_reglk_files(rl_files, flags, ls_p);
		// printf("coloring%scolorado\n", min->data);
		if (dir_files && !dir_files->left && !dir_files->right)
			ft_open_dir(dir_files->data, flags);
		else if (min && dir_files)
			ft_print_open_dir(dir_files, flags, min->data);
		else if (dir_files)
			ft_print_open_dir(dir_files, flags, "");
		if (!av[i] && av[i - 1][0] == '-')
			ft_open_dir(".", flags);
	}
	else
		ft_open_dir(".", flags);
	return (0);
}
