/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 00:16:13 by eurodrig          #+#    #+#             */
/*   Updated: 2017/05/11 15:44:01 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cc(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

static size_t	ft_wc(char const *s, char c)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
			j++;
		while (s[i] != c && s[i + 1] != '\0')
			i++;
		i++;
	}
	return (j);
}

static void		ft_arr(char const *s, char c, char **w, int wc)
{
	size_t		i;
	int			j;
	size_t		k;

	i = 0;
	j = 0;
	k = 0;
	while (j < wc)
	{
		if (!(w[j] = (char *)malloc(sizeof(char) * ft_cc(&s[k], c) + 1)))
			return ;
		while (s[k] == c)
			k++;
		i = 0;
		while (s[k] != c && s[k] != '\0')
			w[j][i++] = (char)s[k++];
		w[j][i] = '\0';
		j++;
	}
	w[j] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	char		**w;
	int			wc;

	if (!s)
		return (NULL);
	wc = ft_wc(s, c);
	if (!(w = (char **)malloc(sizeof(char *) * (wc) + 1)))
		return (NULL);
	ft_arr(s, c, w, wc);
	return (w);
}
