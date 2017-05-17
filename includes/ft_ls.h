/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 03:20:21 by eurodrig          #+#    #+#             */
/*   Updated: 2017/05/16 22:17:18 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libftprintf/includes/libftprintf.h"
#	include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct		s_avl_tree_ls
{
	char *path;
	struct stat f_stat;
	// struct dirent *f_dir;
	char *d_name;
	int d_namlen;
	struct s_avl_tree_ls	*right;
	struct s_avl_tree_ls	*left;
	int						height;
}					t_avl_tree_ls;

typedef struct		s_ls_flags
{
	int l_flag;
	int bigr_flag;
	int a_flag;
	int r_flag;
	int t_flag;
}					t_ls_flags;

t_avl_tree_ls *ft_avl_tree_ls_create(struct dirent *f_dir, char *path);
t_avl_tree_ls *ft_avl_tree_ls_insert(t_avl_tree_ls *root, struct dirent *f_dir, char *path);
void ft_open_dir(char *path, t_ls_flags flags);
t_avl_tree_ls *ft_store_dir(DIR *fd, t_ls_flags flags, char *path);
void ft_avl_tree_ls_r_inorder(t_avl_tree_ls *root, char *path, t_ls_flags flags);
void ft_avl_tree_ls_r_backorder(t_avl_tree_ls *root, char *path, t_ls_flags flags);
int ft_is_node_a_dir(t_avl_tree_ls *root);
int ft_is_a_dir(char *path);

#endif
