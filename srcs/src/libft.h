/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:47:42 by eurodrig          #+#    #+#             */
/*   Updated: 2017/05/25 02:26:48 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 1
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_lst
{
	struct s_lst	*next;
	char			data;
}					t_lst;

typedef struct		s_list_a
{
	void			*data;
	struct s_list_a	*next;
}					t_list_a;

typedef struct		s_list_n
{
	int				data;
	struct s_list_n	*next;
}					t_list_n;

typedef struct		s_list_s
{
	char			*data;
	struct s_list_s	*next;
}					t_list_s;

typedef struct		s_point
{
	size_t			i;
	size_t			j;
}					t_point;

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

void				*ft_memset(void *b, int c, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *big, const char *little, \
		size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s, size_t n);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
int					ft_str_includes(char *str, char c);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void	const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_pwr(size_t n, int pwr);
void				ft_lstprint_s(t_list *lst);
void				ft_lstprint_n(t_list *lst);
size_t				ft_lstlen(t_list *lst);
int					ft_intcmp(int a, int b);
void				ft_lstniter(t_list *lst, void (*f)(t_list *elem), \
		size_t n);
int					get_next_line(const int fd, char **line);
t_lst				*ft_lst_new(char data);
void				ft_lst_push_back(t_lst **begin_lst, char data);
size_t				ft_lst_len(t_lst *lst);
int					ft_str_includes(char *str, char c);
int					ft_lst_includes(t_lst *lst, char c);
char				*ft_lst_to_s(t_lst *lst);
t_list_a			*ft_create_elem(void *data);
void				ft_list_push_back(t_list_a **begin_list, void *data);
void				ft_list_push_front(t_list_a **begin_list, void *data);
int					ft_list_size(t_list_a *begin_list);
t_list_a			*ft_list_last(t_list_a *begin_list);
void				ft_list_clear(t_list_a **begin_list);
t_list_a			*ft_list_at(t_list_a *begin_list, unsigned int nbr);
void				ft_list_reverse(t_list_a **begin_list);
void				ft_list_foreach(t_list_a *begin_list, void (*f)(void *));
void				ft_list_foreach_if(t_list_a *begin_list, void (*f)(void *),\
	void *data_ref, int (*cmp)());
t_list_a			*ft_list_find(t_list_a *begin_list, void *data_ref,\
		int (*cmp)());
void				ft_list_remove_if(t_list_a **begin_list, void *data_ref,\
		int (*cmp)());
void				ft_list_merge(t_list_a **begin_list1,\
		t_list_a *begin_list2);
void				ft_list_sort(t_list_a **begin_list, int (*cmp)());
t_list_a			*ft_list_pop_front(t_list_a **begin_list);
t_list_a			*ft_list_pop_back(t_list_a **begin_list);
int					ft_list_empty(t_list_a **begin_list);
t_btree				*btree_create_node(void *item);
void				btree_free_node(t_btree **root);
t_btree				*btree_insert(t_btree *root, void *item);
void				btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void				btree_apply_infix(t_btree *root, void (*applyf)(void *));
void				btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void				btree_insert_data(t_btree **root, void *item,\
	int (*cmpf)(const char *, const char *));
void				*btree_search_item(t_btree *root, void *data_ref,\
	int (*cmpf)(const char *, const char *));
int					btree_level_count(t_btree *root);
t_btree				*btree_min(t_btree *root);
t_btree				*btree_max(t_btree *root);
t_btree				*btree_delete(t_btree *root, void *data_ref,\
	int (*cmpf)(const char *, const char *));
size_t				ft_max_number(size_t a, size_t b);
t_list_n			*ft_create_elem_n(int data);
void				ft_list_push_back_n(t_list_n **begin_list, int data);
t_list_s			*ft_create_elem_s(char *data);
void				ft_list_push_back_s(t_list_s **begin_list, char *data);
int					ft_list_size_n(t_list_n *begin_list);
int					ft_list_size_s(t_list_s *begin_list);
t_list_n			*ft_list_pop_front_n(t_list_n **begin_list);
void				ft_list_push_front_n(t_list_n **begin_list, int data);
void				ft_list_push_front_s(t_list_s **begin_list, char *data);
t_list_s			*ft_list_pop_back_s(t_list_s **begin_list);
t_list_n			*ft_list_pop_back_n(t_list_n **begin_list);
int					ft_list_includes_n(t_list_n *lst, int n);
int					ft_list_includes_s(t_list_s *lst, char *str);
long long int		ft_atolli(const char *str);
char				*ft_itoa_base_n(int value, int base);
int					ft_list_empty_n(t_list_n **begin_list);
t_list_s			*ft_list_last_s(t_list_s *begin_list);
t_list_n			*ft_list_last_n(t_list_n *begin_list);

#endif
