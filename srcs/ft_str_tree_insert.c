/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tree_insert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 16:57:01 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/03 20:44:18 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_str_tree	*ft_str_tree_insert(t_str_tree *root, char *data)
{
	if (!root)
		root = ft_str_tree_create(data);
	else if (ft_strcmp(data, root->data) > 0)
		root->right = ft_str_tree_insert(root->right, data);
	else
		root->left = ft_str_tree_insert(root->left, data);
	return (root);
}
