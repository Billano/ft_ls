/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 06:32:12 by eurodrig          #+#    #+#             */
/*   Updated: 2017/05/06 02:31:58 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t	ft_uitoa_base_helper(unsigned long long int tmp, int base)
{
	size_t length;

	length = 0;
	while (tmp > 0)
	{
		tmp /= base;
		length++;
	}
	return (length);
}

size_t	ft_itoa_base_helper(long long int tmp, int base)
{
	size_t length;

	length = 0;
	while (tmp > 0)
	{
		tmp /= base;
		length++;
	}
	return (length);
}

char	*ft_uitoa_base_l(unsigned long long int value, int base)
{
	unsigned long long int	tmp;
	char					*str;
	size_t					len;
	char					*nb;

	nb = ft_strdup("0123456789abcdef");
	if (value == 0 || base < 2 || base > 16)
	{
		ft_memdel((void **)&nb);
		return (str = ft_strdup("0"));
	}
	tmp = value;
	len = ft_uitoa_base_helper(tmp, base);
	str = ft_strnew(len);
	tmp = value;
	while (tmp && len--)
	{
		str[len] = nb[tmp % base];
		tmp /= base;
	}
	ft_memdel((void **)&nb);
	return (str);
}

char	*ft_uitoa_base(unsigned long long int value, int base)
{
	unsigned long long int	tmp;
	char					*str;
	size_t					len;
	char					*nb;

	nb = ft_strdup("0123456789ABCDEF");
	if (value == 0 || base < 2 || base > 16)
	{
		ft_memdel((void **)&nb);
		return (str = ft_strdup("0"));
	}
	tmp = value;
	len = ft_uitoa_base_helper(tmp, base);
	str = ft_strnew(len);
	tmp = value;
	while (tmp && len--)
	{
		str[len] = nb[tmp % base];
		tmp /= base;
	}
	ft_memdel((void **)&nb);
	return (str);
}

char	*ft_itoa_base(long long int value, int base)
{
	long long int			tmp;
	char					*str;
	size_t					len;
	char					*nb;

	nb = ft_strdup("0123456789ABCDEF");
	if (value == 0 || base < 2 || base > 16)
	{
		ft_memdel((void **)&nb);
		return (str = ft_strdup("0"));
	}
	if (value < 0)
		value *= -1;
	tmp = value;
	len = ft_itoa_base_helper(tmp, base);
	str = ft_strnew(len);
	tmp = value;
	while (tmp && len--)
	{
		str[len] = nb[tmp % base];
		tmp /= base;
	}
	ft_memdel((void **)&nb);
	return (str);
}
