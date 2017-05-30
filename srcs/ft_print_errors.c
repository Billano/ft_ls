/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:09:56 by eurodrig          #+#    #+#             */
/*   Updated: 2017/05/29 01:24:02 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void ft_print_file_not_found(char *file)
{
	ft_printf("ls: %s: No such File or directory\n", file);
}

void ft_print_illegal_option(char c)
{
	ft_printf("ls: illegal option -- %c\n", c);
	ft_printf("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n");//"usage: ./ft_ls [-Ralrt] [file ...]\n");
}
