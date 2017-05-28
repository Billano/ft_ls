/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_symbol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 21:55:51 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/17 02:06:57 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_printf_symbol(char *flags)
{
	if (ft_printf_str_contains(flags, '+') ||
			ft_printf_str_contains(flags, ' '))
		return (1);
	return (0);
}
