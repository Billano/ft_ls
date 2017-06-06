/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_diff_six.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 19:59:04 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/01 20:09:07 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	ft_time_diff_six(time_t file)
{
	time_t sys;

	time(&sys);
	if (((file - sys) > 15552000) || ((file - sys) < -15552000))
		return (1);
	return (0);
}
