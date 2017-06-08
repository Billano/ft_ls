/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 03:13:47 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/07 22:43:21 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_ls.h"

int	main(int ac, char **av)
{
	t_ls_flags	flags;
	int			i;

	i = 1;
	flags = ft_flags_init();
	if (!ft_flags_parser(ac, av, &i, &flags))
		return (0);
	if (ac > 1)
		ft_param_handle(av, i, flags);
	else
		ft_open_dir(".", flags);
	return (0);
}
