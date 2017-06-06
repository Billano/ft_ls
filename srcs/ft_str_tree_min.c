/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tree_min.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 00:27:47 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/06 00:28:00 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_str_tree	*ft_str_tree_min(t_str_tree *root)
{
	if (!root)
		return (0);
	if (!root->left)
		return (root);
	return (root->left);
}
