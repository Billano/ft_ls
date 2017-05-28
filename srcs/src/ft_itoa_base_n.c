/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 06:09:38 by eurodrig          #+#    #+#             */
/*   Updated: 2017/05/09 02:46:39 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_base_n_helper(int tmp, int len, char *arr, int base)
{
	char *nb;

	nb = ft_strdup("0123456789ABCDEF");
	while (tmp && len--)
	{
		arr[len] = nb[tmp % base];
		tmp /= base;
	}
	ft_memdel((void **)&nb);
}

char		*ft_itoa_base_n(int value, int base)
{
	int		tmp;
	char	*arr;
	int		len;

	if (!value || base < 2 || 16 < base)
		return (ft_strdup("0"));
	if (value == -2147483648 && base == 10)
		return (ft_strdup("-2147483648"));
	if (value < 0 && base != 10)
		value = -value;
	tmp = (value < 0) ? -value : value;
	len = (value < 0) ? 2 : 1;
	while (tmp > base - 1)
	{
		tmp = tmp / base;
		len++;
	}
	arr = ft_strnew(len);
	tmp = (value < 0) ? -value : value;
	ft_itoa_base_n_helper(tmp, len, arr, base);
	if (value < 0)
		arr[0] = '-';
	return (arr);
}
