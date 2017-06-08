/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tree_includes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 20:15:04 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/06 20:47:27 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	ft_str_tree_includes(t_str_tree *root, char *str)
{
	if (root)
	{
		if (ft_strcmp(root->data, str) > 0)
			return (ft_str_tree_includes(root->left, str));
		else if (ft_strcmp(root->data, str) < 0)
			return (ft_str_tree_includes(root->right, str));
		else
			return (1);
	}
	else
		return (0);
}
