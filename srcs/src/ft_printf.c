/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 22:01:12 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/19 04:55:24 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_printf_helper_d(va_list ap, t_param *params, int *length, char *s)
{
	if (*s && s[params->strlen - 1] == 'X')
		*length += ft_printf_lx(ap, params);
	else if (*s && s[params->strlen - 1] == 'p')
	{
		params->flags = ft_strcat(params->flags, "ll#");
		*length += ft_printf_x_l_int(ap, params);
	}
	else if (*s && s[params->strlen - 1] == 'n')
		ft_printf_n(ap, params, *length);
	else
		va_arg(ap, void *);
}

void	ft_printf_helper_c(va_list ap, t_param *params, int *length, char *s)
{
	if (*s && s[params->strlen - 1] == 's')
		*length += ft_printf_s(ap, params);
	else if (*s && s[params->strlen - 1] == 'S')
		*length += ft_printf_ls(ap, params);
	else if (*s && s[params->strlen - 1] == 'c')
		*length += ft_printf_c(ap, params);
	else if (*s && s[params->strlen - 1] == 'C')
		*length += ft_printf_lc(ap, params);
	else if (*s && (s[params->strlen - 1] == 'd' ||
		s[params->strlen - 1] == 'i'))
		*length += ft_printf_d(ap, params);
	else if (*s && s[params->strlen - 1] == 'D')
		*length += ft_printf_d_l_int(ap, params);
	else if (*s && s[params->strlen - 1] == 'u')
		*length += ft_printf_u(ap, params);
	else if (*s && s[params->strlen - 1] == 'U')
		*length += ft_printf_u_l_int(ap, params);
	else if (*s && s[params->strlen - 1] == 'o')
		*length += ft_printf_o(ap, params);
	else if (*s && s[params->strlen - 1] == 'O')
		*length += ft_printf_o_l_int(ap, params);
	else if (*s && s[params->strlen - 1] == 'x')
		*length += ft_printf_x(ap, params);
	else
		ft_printf_helper_d(ap, params, length, s);
}

void	ft_printf_helper_b(va_list ap, const char **format, int *length)
{
	t_param	*params;
	char	*s;

	params = 0;
	if (**format == '%')
	{
		(*format)++;
		s = ft_printf_str_trim(*format);
		params = ft_printf_params_init(s, ap);
		if (*s && s[params->strlen - 1] == '%')
			*length += ft_printf_percent(params);
		else
			ft_printf_helper_c(ap, params, length, s);
		(*format) += params->strlen;
		ft_multiple_memdel("4", (void **)&(params->flags),
			(void **)&(params->length), (void **)&params, (void **)&s);
	}
}

int		ft_printf_helper_a(va_list ap, const char *format)
{
	int		length;

	length = 0;
	while (*format)
	{
		ft_printf_helper_b(ap, &format, &length);
		if (!*format)
			break ;
		if (*format != '%')
		{
			ft_putchar(*format);
			length += 1;
			format++;
		}
	}
	return (length);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		length;

	length = 0;
	va_start(ap, format);
	length = ft_printf_helper_a(ap, format);
	va_end(ap);
	return (length);
}
