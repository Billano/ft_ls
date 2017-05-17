/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 01:38:55 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/18 01:38:56 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_printf_ls_helper(t_param *params, wchar_t *str, size_t length)
{
	if (ft_printf_str_contains(params->flags, '-'))
	{
		if (params->precision)
			ft_printf_print_lsp(params, str);
		else
			ft_printf_print_ls(str);
		ft_print_blank_s(params, length);
	}
	else
	{
		ft_print_blank_s(params, length);
		if (params->precision)
			ft_printf_print_lsp(params, str);
		else
			ft_printf_print_ls(str);
	}
}

void	ft_printf_s_helper(t_param *params, char *str, size_t length)
{
	if (ft_printf_str_contains(params->flags, '-'))
	{
		ft_printf_print_s(params, str);
		ft_print_blank_s(params, length);
	}
	else
	{
		ft_print_blank_s(params, length);
		ft_printf_print_s(params, str);
	}
}
