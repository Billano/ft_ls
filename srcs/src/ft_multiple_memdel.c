/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiple_memdel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 01:05:21 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/18 01:37:07 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_multiple_memdel(const char *format, ...)
{
	va_list ap;
	int		n;

	va_start(ap, format);
	n = ft_atoi(format);
	while (n > 0)
	{
		ft_memdel(va_arg(ap, void **));
		n--;
	}
}
