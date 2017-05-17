/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:33:44 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/10 17:33:45 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*btree_insert(t_btree *root, void *item)
{
	if (!root)
		root = btree_create_node(item);
	else if (root->item <= item)
		root->left = btree_insert(root->left, item);
	else
		root->right = btree_insert(root->right, item);
	return (root);
}
