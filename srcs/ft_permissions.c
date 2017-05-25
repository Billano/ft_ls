/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permissions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:09:20 by eurodrig          #+#    #+#             */
/*   Updated: 2017/05/23 21:57:52 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void ft_permission_update(t_avl_tree_ls *root, t_ls_permisions *ls_p)
{
	ls_p->blocks += root->blocks;
	if (ls_p->permission_len < ft_strlen(root->permission))
		ls_p->permission_len = ft_strlen(root->permission);
	if (ls_p->link_num_len < ft_strlen(root->link_num))
		ls_p->link_num_len = ft_strlen(root->link_num);
	if (ls_p->owner_name_len < ft_strlen(root->owner_name))
		ls_p->owner_name_len = ft_strlen(root->owner_name);
	if (ls_p->group_name_len < ft_strlen(root->group_name))
		ls_p->group_name_len = ft_strlen(root->group_name);
	if (ls_p->size_len < ft_strlen(root->size))
		ls_p->size_len = ft_strlen(root->size);
}

char	ft_set_acl(char *path)
{
	acl_t acl;
	acl_entry_t dummy;
	ssize_t xattr;

	acl = 0;
	xattr = 0;
	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (xattr < 0)
		xattr = 0;
	if (xattr > 0)
		return ('@');
	else if (acl != NULL)
		return ('+');
	else
		return (' ');
}

char *ft_file_permisions(t_ls_data *ls_data, char *path)
{
	char *str;

	str = ft_strnew(12);
	str[0] = ft_file_type(ls_data);
	str[1] = (ls_data->f_stat.st_mode & S_IRUSR) ? 'r' : '-';
	str[2] = (ls_data->f_stat.st_mode & S_IWUSR) ? 'w' : '-';
	str[3] = (ls_data->f_stat.st_mode & S_IXUSR) ? 'x' : '-';
	str[4] = (ls_data->f_stat.st_mode & S_IRGRP) ? 'r' : '-';
	str[5] = (ls_data->f_stat.st_mode & S_IWGRP) ? 'w' : '-';
	str[6] = (ls_data->f_stat.st_mode & S_IXGRP) ? 'x' : '-';
	str[7] = (ls_data->f_stat.st_mode & S_IROTH) ? 'r' : '-';
	str[8] = (ls_data->f_stat.st_mode & S_IWOTH) ? 'w' : '-';
	str[9] = (ls_data->f_stat.st_mode & S_IXOTH) ? 'x' : '-';
	str[10] = ft_set_acl(path);
	return (str);
}

char ft_file_type(t_ls_data *ls_data)
{
	if (S_ISDIR(ls_data->f_stat.st_mode))
		return ('d');
	else if (S_ISREG(ls_data->f_stat.st_mode))
		return ('-');
	else if (S_ISLNK(ls_data->f_stat.st_mode))
		return ('l');
	else if (S_ISCHR(ls_data->f_stat.st_mode))
		return ('c');
	else if (S_ISBLK(ls_data->f_stat.st_mode))
		return ('b');
	else if (S_ISFIFO(ls_data->f_stat.st_mode))
		return ('p');
	else if (S_ISSOCK(ls_data->f_stat.st_mode))
		return ('s');
	else
		return ('.');
}
