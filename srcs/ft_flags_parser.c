/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:04:35 by eurodrig          #+#    #+#             */
/*   Updated: 2017/05/29 22:48:32 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_ls_flags ft_flags_init(void)
{
	t_ls_flags flags;

	flags.l_flag = 0;
	flags.bigr_flag = 0;
	flags.a_flag = 0;
	flags.r_flag = 0;
	flags.t_flag = 0;
	return (flags);
}

int ft_flags_update(char *str, t_ls_flags *flags)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (str[i] == 'l')
			flags->l_flag = 1;
		else if (str[i] == 'R')
			flags->bigr_flag = 1;
		else if (str[i] == 'a')
			flags->a_flag = 1;
		else if (str[i] == 'r')
			flags->r_flag = 1;
		else if (str[i] == 't')
			flags->t_flag = 1;
		else if (str[i] == '1')
			;
		else
		{
			ft_print_illegal_option(str[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

int ft_flags_parser(int ac, char **av, int *i, t_ls_flags *flags)
{
	if (ac > 1)
	{
		while (av[(*i)] && av[(*i)][0] == '-' && ft_strcmp("--", av[(*i)]))
		{
			// printf("i:%d, l_flag: %d, R_flag: %d, a: %d r: %d t: %d\n", (*i), flags.l_flag, flags.bigr_flag, flags.a_flag, flags.r_flag, flags.t_flag);
			if (!ft_flags_update(av[(*i)], flags))
				return (0);
			// printf("i:%d, l_flag: %d, R_flag: %d, a: %d r: %d t: %d\n", (*i), flags.l_flag, flags.bigr_flag, flags.a_flag, flags.r_flag, flags.t_flag);
			(*i)++;
		}
		if (av[(*i)] && !ft_strcmp("--", av[(*i)]))
			(*i)++;
	}
	// printf("i:%d, l_flag: %d, R_flag: %d, a: %d r: %d t: %d\n", (*i), flags.l_flag, flags.bigr_flag, flags.a_flag, flags.r_flag, flags.t_flag);
	return (1);
}
