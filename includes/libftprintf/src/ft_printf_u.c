/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:28:17 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/17 01:26:36 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t	ft_printf_u_l_int(va_list ap, t_param *params)
{
	unsigned long int	n;
	char				*nbr;
	size_t				length;

	length = 0;
	n = va_arg(ap, unsigned long int);
	nbr = ft_uitoa_base(n, 10);
	length = ft_strlen(nbr);
	if (params->precision_flag && params->precision == 0 && *nbr == '0')
		length = 0;
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_u_int(va_list ap, t_param *params)
{
	unsigned int			n;
	char					*nbr;
	size_t					length;

	length = 0;
	n = va_arg(ap, unsigned int);
	nbr = ft_uitoa_base(n, 10);
	length = ft_strlen(nbr);
	if (params->precision_flag && params->precision == 0 && *nbr == '0')
		length = 0;
	ft_print_d(params, length, nbr);
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_u(va_list ap, t_param *params)
{
	size_t					length;

	length = 0;
	if (ft_strcmp(params->length, "h") == 0)
		length += ft_printf_u_int(ap, params);
	else if (ft_strcmp(params->length, "hh") == 0)
		length += ft_printf_u_int(ap, params);
	else if (ft_strcmp(params->length, "l") == 0)
		length += ft_printf_u_l_int(ap, params);
	else if (ft_strcmp(params->length, "ll") == 0)
		length += ft_printf_u_l_l_int(ap, params);
	else if (ft_strcmp(params->length, "j") == 0)
		length += ft_printf_u_intmax_t(ap, params);
	else if (ft_strcmp(params->length, "z") == 0)
		length += ft_printf_u_size_t(ap, params);
	else
		length += ft_printf_u_int(ap, params);
	return (length);
}
