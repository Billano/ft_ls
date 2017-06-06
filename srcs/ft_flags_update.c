/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 18:59:47 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/02 16:36:08 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	ft_flags_update(char *str, t_ls_flags *flags)
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
