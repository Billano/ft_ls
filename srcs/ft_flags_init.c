/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 18:54:49 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/07 02:56:12 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_ls_flags	ft_flags_init(void)
{
	t_ls_flags flags;

	flags.l_flag = 0;
	flags.bigr_flag = 0;
	flags.a_flag = 0;
	flags.r_flag = 0;
	flags.t_flag = 0;
	flags.o_flag = 0;
	flags.bigt_flag = 0;
	return (flags);
}
