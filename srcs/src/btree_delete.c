/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:36:32 by eurodrig          #+#    #+#             */
/*   Updated: 2017/03/10 17:36:33 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_delete_helper(t_btree **root, void *data_ref,\
	int (*cmpf)(const char*, const char*))
{
	t_btree *tmp;

	if ((*root)->right == NULL && (*root)->left == NULL)
	{
		btree_free_node(root);
	}
	else if ((*root)->right == NULL)
	{
		tmp = (*root);
		(*root) = (*root)->left;
		btree_free_node(&tmp);
	}
	else if ((*root)->left == NULL)
	{
		tmp = (*root);
		(*root) = (*root)->right;
		btree_free_node(&tmp);
	}
	else
	{
		tmp = btree_min((*root)->right);
		(*root)->item = tmp->item;
		btree_delete((*root)->right, data_ref, cmpf);
	}
}

t_btree	*btree_delete(t_btree *root, void *data_ref,\
	int (*cmpf)(const char *, const char *))
{
	if (!root)
		return (NULL);
	else if ((*cmpf)(root->item, data_ref) > 0)
		btree_delete(root->left, data_ref, cmpf);
	else if ((*cmpf)(root->item, data_ref) < 0)
		btree_delete(root->right, data_ref, cmpf);
	else
	{
		btree_delete_helper(&root, data_ref, cmpf);
	}
	return (root);
}
