/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 22:40:47 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/16 22:40:48 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_printf_n_intmax_t(va_list ap, size_t length)
{
	intmax_t *n;

	n = va_arg(ap, intmax_t *);
	*n = length;
}

void	ft_printf_n_l_l_int(va_list ap, size_t length)
{
	long long int *n;

	n = va_arg(ap, long long int *);
	*n = length;
}

void	ft_printf_n_l_int(va_list ap, size_t length)
{
	long int *n;

	n = va_arg(ap, long int *);
	*n = length;
}

void	ft_printf_n_int(va_list ap, size_t length)
{
	int *n;

	n = va_arg(ap, int *);
	*n = length;
}

void	ft_printf_n(va_list ap, t_param *params, size_t length)
{
	if (ft_strcmp(params->length, "h") == 0)
		ft_printf_n_int(ap, length);
	else if (ft_strcmp(params->length, "hh") == 0)
		ft_printf_n_int(ap, length);
	else if (ft_strcmp(params->length, "l") == 0)
		ft_printf_n_l_int(ap, length);
	else if (ft_strcmp(params->length, "ll") == 0)
		ft_printf_n_l_l_int(ap, length);
	else if (ft_strcmp(params->length, "j") == 0)
		ft_printf_n_intmax_t(ap, length);
	else if (ft_strcmp(params->length, "z") == 0)
		ft_printf_n_size_t(ap, length);
	else
		ft_printf_n_int(ap, length);
}
