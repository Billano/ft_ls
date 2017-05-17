/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_tree_item.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:34:52 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/10 17:34:53 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*btree_search_item(t_btree *root, void *data_ref, \
	int (*cmpf)(const char *, const char *))
{
	if (!root)
		return (NULL);
	else if ((*cmpf)(root->item, data_ref) > 0)
		return (btree_search_item(root->left, data_ref, cmpf));
	else if ((*cmpf)(root->item, data_ref) == 0)
		return (root);
	else
		return (btree_search_item(root->right, data_ref, cmpf));
}
