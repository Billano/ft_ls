/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 03:20:21 by eurodrig          #+#    #+#             */
/*   Updated: 2017/05/24 21:16:31 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libftprintf/includes/libftprintf.h"
#	include <dirent.h>
#	include <sys/types.h>
#	include <sys/stat.h>
# include <sys/xattr.h>
#	include <sys/acl.h>
#	include <grp.h>
#	include <pwd.h>
#	include <time.h>

typedef struct		s_avl_tree_ls
{
	char *path;
	struct stat f_stat;
	char *d_name;
	char *permission;
	char *link_num;
	char *owner_name;
	char *group_name;
	char *size;
	long long int blocks;
	struct s_avl_tree_ls	*right;
	struct s_avl_tree_ls	*left;
}					t_avl_tree_ls;

typedef struct  s_str_tree
{
	char *data;
	struct s_str_tree *right;
	struct s_str_tree *left;
}					t_str_tree;

typedef struct		s_ls_flags
{
	int l_flag:1;
	int bigr_flag:1;
	int a_flag:1;
	int r_flag:1;
	int t_flag:1;
}					t_ls_flags;

typedef struct s_ls_permisions
{
	int blocks;
	size_t permission_len;
	size_t link_num_len;
	size_t owner_name_len;
	size_t group_name_len;
	size_t size_len;
}				t_ls_permisions;

typedef struct s_ls_data
{
	struct stat f_stat;
	struct dirent *f_dir;
	char *path;
}				t_ls_data;

int ft_flags_parser(int ac, char **av, int *i, t_ls_flags *flags);
int ft_flags_update(char *str, t_ls_flags *flags);
t_ls_flags ft_flags_init(void);


t_str_tree *ft_folder_validator(int i, char **av);

void ft_ls_print_long(t_avl_tree_ls *root, t_ls_permisions *ls_p);


void ft_print_file_not_found(char *file);
void ft_print_illegal_option(char c);
void ft_print_e_files(t_str_tree *root);

t_ls_data *ft_ls_data_init(struct dirent *f_dir, struct stat f_stat, char *path);

t_str_tree *ft_str_tree_create(char *data);
t_str_tree *ft_str_tree_insert(t_str_tree *root, char *data);



t_avl_tree_ls *ft_avl_tree_ls_create(t_ls_data *ls_data);
t_avl_tree_ls *ft_avl_tree_ls_insert(t_avl_tree_ls *root, t_ls_data *ls_data, t_ls_permisions *ls_p);
void ft_open_dir(char *path, t_ls_flags flags);
t_avl_tree_ls *ft_store_dir(DIR *fd, t_ls_flags flags, char *path, t_ls_permisions *ls_p);
void ft_avl_tree_ls_r_inorder(t_avl_tree_ls *root, char *path, t_ls_flags flags);
void ft_avl_tree_ls_r_backorder(t_avl_tree_ls *root, char *path, t_ls_flags flags);
int ft_is_node_a_dir(t_avl_tree_ls *root);
int ft_is_a_dir(char *path);

void ft_permission_update(t_avl_tree_ls *root, t_ls_permisions *ls_p);
char *ft_file_permisions(t_ls_data *ls_data, char *path);
char ft_file_type(t_ls_data *ls_data);

#endif
