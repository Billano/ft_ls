/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tree_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 20:36:03 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/05 19:48:29 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_str_tree	*ft_str_tree_create(char *data)
{
	t_str_tree *root;

	root = 0;
	if (!(root = (t_str_tree *)malloc(sizeof(t_str_tree))))
		return (0);
	root->data = ft_strdup(data);
	root->right = 0;
	root->left = 0;
	return (root);
}
