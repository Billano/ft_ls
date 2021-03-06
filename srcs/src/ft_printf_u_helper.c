/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:35:20 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/17 01:27:54 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t	ft_printf_u_size_t(va_list ap, t_param *params)
{
	size_t					n;
	char					*nbr;
	size_t					length;

	length = 0;
	n = va_arg(ap, size_t);
	nbr = ft_uitoa_base(n, 10);
	length = ft_strlen(nbr);
	if (params->precision_flag && params->precision == 0 && *nbr == '0')
		length = 0;
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_u_intmax_t(va_list ap, t_param *params)
{
	uintmax_t				n;
	char					*nbr;
	size_t					length;

	length = 0;
	n = va_arg(ap, uintmax_t);
	nbr = ft_uitoa_base(n, 10);
	length = ft_strlen(nbr);
	if (params->precision_flag && params->precision == 0 && *nbr == '0')
		length = 0;
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_u_l_l_int(va_list ap, t_param *params)
{
	unsigned long long int	n;
	char					*nbr;
	size_t					length;

	length = 0;
	n = va_arg(ap, unsigned long long int);
	nbr = ft_uitoa_base(n, 10);
	length = ft_strlen(nbr);
	if (params->precision_flag && params->precision == 0 && *nbr == '0')
		length = 0;
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}
