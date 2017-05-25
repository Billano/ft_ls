/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:14:16 by eurodrig          #+#    #+#             */
/*   Updated: 2016/12/05 23:14:54 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_point	ft_side_trim(char const *s)
{
	t_point w;

	w.i = 0;
	while ((s[w.i] == '\t' || s[w.i] == '\n' || s[w.i] == ' ') && s[w.i])
		w.i++;
	w.j = ft_strlen(s) - 1;
	while ((s[w.j] == '\t' || s[w.j] == '\n' || s[w.j] == ' ') && w.j)
		w.j--;
	return (w);
}

static t_point	ft_ar_maker(char const *s, char *new, t_point ij, t_point w)
{
	while (s[ij.i])
	{
		if (ij.i >= w.i && ij.i <= w.j)
			new[ij.j++] = s[ij.i];
		ij.i++;
	}
	new[ij.j] = '\0';
	return (ij);
}

char			*ft_strtrim(char const *s)
{
	t_point ij;
	t_point w;
	char	*new;

	if (!s)
		return (NULL);
	ij.i = 0;
	ij.j = 0;
	w = ft_side_trim(s);
	if (w.j < w.i)
	{
		if ((new = (char *)malloc(sizeof(char))) == NULL)
			return (NULL);
	}
	else
	{
		if ((new = (char *)malloc(sizeof(char) * (w.j - w.i) + 2)) == NULL)
			return (NULL);
		ij = ft_ar_maker(s, new, ij, w);
	}
	new[ij.j] = '\0';
	return (new);
}
