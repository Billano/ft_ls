/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 02:49:36 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/09 02:49:38 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_printf_flags(char *str)
{
	char	*flags;
	size_t	n;

	n = 0;
	while (str[n] == '-' || str[n] == '+' || str[n] == ' ' || str[n] == '#'
		|| str[n] == '0')
		n++;
	flags = ft_strnew(n);
	n = 0;
	while (str[n] == '-' || str[n] == '+' || str[n] == ' ' || str[n] == '#'
		|| str[n] == '0')
	{
		flags[n] = str[n];
		n++;
	}
	flags[n] = '\0';
	return (flags);
}
