/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_params_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 02:45:19 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/09 02:45:25 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_param	*ft_printf_params_init(char *str, va_list ap)
{
	t_param *params;

	if (!(params = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	params->flags = ft_printf_flags(str);
	params->width = ft_printf_width(str, ap);
	params->precision = ft_printf_precision(str, ap);
	params->length = ft_printf_length(str);
	params->sign = 0;
	params->strlen = ft_strlen(str);
	params->specifier = str[params->strlen - 1];
	params->symbol = ft_printf_symbol(params->flags);
	params->precision_flag = ft_printf_precision_flag(str);
	return (params);
}
