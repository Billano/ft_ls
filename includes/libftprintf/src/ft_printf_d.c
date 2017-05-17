/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 06:34:02 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/13 18:15:03 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t	ft_printf_d_intmax_t(va_list ap, t_param *params)
{
	intmax_t	n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, intmax_t);
	if (n < 0)
	{
		params->sign = 1;
		params->symbol = 1;
	}
	nbr = ft_itoa_base(n, 10);
	length = ft_strlen(nbr);
	if (params->precision_flag && params->precision == 0 && *nbr == '0')
		length = 0;
	ft_print_d(params, length, nbr);
	if (params->symbol == 1)
		length += 1;
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_d_l_l_int(va_list ap, t_param *params)
{
	long long int	n;
	char			*nbr;
	size_t			length;

	length = 0;
	n = va_arg(ap, long long int);
	if (n < 0)
	{
		params->sign = 1;
		params->symbol = 1;
	}
	nbr = ft_itoa_base(n, 10);
	length = ft_strlen(nbr);
	if (params->precision_flag && params->precision == 0 && *nbr == '0')
		length = 0;
	ft_print_d(params, length, nbr);
	if (params->symbol == 1)
		length += 1;
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_d_l_int(va_list ap, t_param *params)
{
	long int	n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, long int);
	if (n < 0)
	{
		params->sign = 1;
		params->symbol = 1;
	}
	nbr = ft_itoa_base(n, 10);
	length = ft_strlen(nbr);
	if (params->precision_flag && params->precision == 0 && *nbr == '0')
		length = 0;
	ft_print_d(params, length, nbr);
	if (params->symbol == 1)
		length += 1;
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_d_int(va_list ap, t_param *params)
{
	int			n;
	char		*nbr;
	size_t		length;

	length = 0;
	n = va_arg(ap, int);
	if (n < 0)
	{
		params->sign = 1;
		params->symbol = 1;
	}
	nbr = ft_itoa_base(n, 10);
	length = ft_strlen(nbr);
	if (params->precision_flag && params->precision == 0 && *nbr == '0')
		length = 0;
	ft_print_d(params, length, nbr);
	if (params->symbol == 1)
		length += 1;
	length = ft_max_number(length,\
		ft_max_number(params->width, params->precision));
	return (length);
}

size_t	ft_printf_d(va_list ap, t_param *params)
{
	size_t		length;

	length = 0;
	if (ft_strcmp(params->length, "h") == 0)
		length += ft_printf_d_int(ap, params);
	else if (ft_strcmp(params->length, "hh") == 0)
		length += ft_printf_d_int(ap, params);
	else if (ft_strcmp(params->length, "l") == 0)
		length += ft_printf_d_l_int(ap, params);
	else if (ft_strcmp(params->length, "ll") == 0)
		length += ft_printf_d_l_l_int(ap, params);
	else if (ft_strcmp(params->length, "j") == 0)
		length += ft_printf_d_intmax_t(ap, params);
	else if (ft_strcmp(params->length, "z") == 0)
		length += ft_printf_d_size_t(ap, params);
	else
		length += ft_printf_d_int(ap, params);
	return (length);
}
