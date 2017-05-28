/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 20:44:22 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/17 02:03:44 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_printf_print_lsp(t_param *params, wchar_t *str)
{
	size_t	i;
	wchar_t	n;

	i = 0;
	while (str[i] && i < params->precision)
	{
		n = str[i];
		if (n <= 255)
			ft_putchar(str[i]);
		else if (n <= 2047)
			ft_putchar_n_bytes(str[i], 2);
		else if (n <= 65535)
			ft_putchar_n_bytes(str[i], 3);
		else if (n <= 1114111)
			ft_putchar_n_bytes(str[i], 4);
		i++;
	}
}

void	ft_printf_print_ls(wchar_t *str)
{
	size_t	i;
	wchar_t	n;

	i = 0;
	while (str[i])
	{
		n = str[i];
		if (n <= 255)
			ft_putchar(str[i]);
		else if (n <= 2047)
			ft_putchar_n_bytes(str[i], 2);
		else if (n <= 65535)
			ft_putchar_n_bytes(str[i], 3);
		else if (n <= 1114111)
			ft_putchar_n_bytes(str[i], 4);
		i++;
	}
}

size_t	ft_printf_ls(va_list ap, t_param *params)
{
	wchar_t	*str;
	size_t	length;

	str = va_arg(ap, wchar_t *);
	if (!str)
	{
		ft_putstr("(null)");
		return (0);
	}
	length = ft_wstrlen(str);
	if (params->precision < length && params->precision != 0)
		length = params->precision;
	ft_printf_ls_helper(params, str, length);
	return (ft_max_number(params->width, length));
}

void	ft_printf_print_s(t_param *params, char *str)
{
	size_t i;

	i = 0;
	if (params->precision)
	{
		while (str[i] && i < params->precision)
			ft_putchar(str[i++]);
	}
	else
	{
		while (str[i])
			ft_putchar(str[i++]);
	}
}

size_t	ft_printf_s(va_list ap, t_param *params)
{
	char	*str;
	size_t	length;

	if (*(params->length) != 'l')
	{
		str = va_arg(ap, char *);
		if (!str)
		{
			ft_putstr("(null)");
			return (0);
		}
		length = ft_strlen(str);
		if (params->precision < length && params->precision != 0)
			length = params->precision;
		ft_printf_s_helper(params, str, length);
		return (ft_max_number(params->width, length));
	}
	return (ft_printf_ls(ap, params));
}
