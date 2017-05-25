/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_empty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:19:07 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/10 17:19:09 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_list_empty(t_list_a **begin_list)
{
	if (*begin_list == NULL)
		return (1);
	else
		return (0);
}

int	ft_list_empty_n(t_list_n **begin_list)
{
	if (*begin_list == NULL)
		return (1);
	else
		return (0);
}
