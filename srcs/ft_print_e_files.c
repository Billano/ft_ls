/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_e_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 20:43:32 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/01 20:44:51 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_print_e_files(t_str_tree *root)
{
	if (root)
	{
		ft_print_e_files(root->left);
		ft_print_file_not_found(root->data);
		ft_print_e_files(root->right);
	}
}
