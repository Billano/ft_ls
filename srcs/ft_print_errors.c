/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:09:56 by eurodrig          #+#    #+#             */
/*   Updated: 2017/05/18 23:13:19 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void ft_print_file_not_found(char *file)
{
	ft_printf("ft_ls: %s: No such File or directory\n", file);
}

void ft_print_illegal_option(char c)
{
	ft_printf("ft_ls: illegal option -- %c\n", c);
	ft_printf("usage: ./ft_ls [-Ralrt] [file ...]\n");
}
