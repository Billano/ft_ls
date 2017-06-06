/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:09:56 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/06 03:32:43 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void ft_print_file_not_found(char *file)
{
	// perror("ls: ");
	ft_putstr_fd("ls: ", 2);
	ft_strlen(file) == 0 ? ft_putstr_fd("fts_open", 2) : ft_putstr_fd(file, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	// perror(ft_strjoin("ls: ", file));
	// perror(": No such file or directory\n");
	// ft_printf("ls: %s: No such file or directory\n", file);
}

void ft_print_illegal_option(char c)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", 2);
}
