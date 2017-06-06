/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:04:35 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/02 16:37:18 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	ft_flags_parser(int ac, char **av, int *i, t_ls_flags *flags)
{
	if (ac > 1)
	{
		while (av[(*i)] && av[(*i)][0] == '-' && ft_strncmp("--", av[(*i)], 2)\
		&& ft_strlen(av[(*i)]) > 1)
		{
			if (!ft_flags_update(av[(*i)], flags))
				return (0);
			(*i)++;
		}
		if (av[(*i)] && !ft_strcmp("--", av[(*i)]))
			(*i)++;
	}
	return (1);
}
