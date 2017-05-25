/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tree_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 00:43:33 by eurodrig          #+#    #+#             */
/*   Updated: 2017/05/23 02:10:23 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_str_tree *ft_str_tree_create(char *data)
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

t_str_tree *ft_str_tree_insert(t_str_tree *root, char *data)
{
	if (!root)
		root = ft_str_tree_create(data);
	else if (ft_strcmp(data, root->data) > 0)
		root->right = ft_str_tree_insert(root->right, data);
	else
		root->left = ft_str_tree_insert(root->left, data);
	return (root);
}

void ft_print_e_files(t_str_tree *root)
{
	if (root)
	{
		ft_print_e_files(root->left);
		ft_print_file_not_found(root->data);
		ft_print_e_files(root->right);
	}
}
