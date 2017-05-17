/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 03:18:20 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/09 03:18:22 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t	ft_printf_width(char *str, va_list ap)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '1' && str[i] <= '9') || str[i] == '.' || str[i] == '*')
			break ;
		i++;
	}
	if (!str[i] || str[i] == '.')
		return (0);
	if (str[i] == '*')
		return (va_arg(ap, int));
	return (ft_atoi(str + i));
}
