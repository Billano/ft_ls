/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 21:42:33 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/17 02:00:22 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t	ft_printf_lx_l_int(va_list ap, t_param *params)
{
	unsigned long int	n;
	char				*nbr;
	size_t				length;

	length = 0;
	n = va_arg(ap, unsigned long int);
	nbr = ft_uitoa_base(n, 16);
	length = ft_strlen(nbr);
	if (ft_printf_str_contains(params->flags, '#') && length == 1 &&
			*nbr == '0')
		params->sign = -1;
	if (ft_printf_str_contains(params->flags, '#') && params->sign == 0)
		length += 2;
	if (params->precision_flag && params->precision == 0 && *nbr == '0')
		length = 0;
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_lx_int(va_list ap, t_param *params)
{
	unsigned int	n;
	char			*nbr;
	size_t			length;

	length = 0;
	n = va_arg(ap, unsigned int);
	nbr = ft_uitoa_base(n, 16);
	length = ft_strlen(nbr);
	if (ft_printf_str_contains(params->flags, '#') && length == 1 &&
			*nbr == '0')
		params->sign = -1;
	if (ft_printf_str_contains(params->flags, '#') && params->sign == 0)
		length += 2;
	if (params->precision_flag && params->precision == 0 && *nbr == '0')
		length = 0;
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_lx(va_list ap, t_param *params)
{
	size_t		length;

	length = 0;
	if (ft_strcmp(params->length, "h") == 0)
		length += ft_printf_lx_int(ap, params);
	else if (ft_strcmp(params->length, "hh") == 0)
		length += ft_printf_lx_int(ap, params);
	else if (ft_strcmp(params->length, "l") == 0)
		length += ft_printf_lx_l_int(ap, params);
	else if (ft_strcmp(params->length, "ll") == 0)
		length += ft_printf_lx_l_l_int(ap, params);
	else if (ft_strcmp(params->length, "j") == 0)
		length += ft_printf_lx_intmax_t(ap, params);
	else if (ft_strcmp(params->length, "z") == 0)
		length += ft_printf_lx_size_t(ap, params);
	else
		length += ft_printf_lx_int(ap, params);
	return (length);
}
