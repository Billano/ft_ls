/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_contains.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 05:34:00 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/09 05:34:02 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_printf_str_contains(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		if (*str >= '1' && *str <= '9')
			return (0);
		str++;
	}
	return (0);
}
