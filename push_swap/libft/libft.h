/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:19:03 by dbaule            #+#    #+#             */
/*   Updated: 2023/01/13 14:34:20 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_atoi(const char *a);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elementCount, size_t elementSize);
int		ft_isalnum(int a);
int		ft_isalpha(int c);
int		ft_isascii(int a);
int		ft_isdigit(int c);
int		ft_isprint(int a);
void	*ft_memchr( const void *memoryBlock, int searchedChar, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *destination, const void *source, size_t size);
void	*ft_memset(void *pointer, int value, size_t count);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *a, int c);
char	*ft_dup(const char *src, char *tab);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlcat(char *dest, char const *src, unsigned long size);
size_t	ft_strlen(const char *string);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *a, const char *b, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *a, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int a);
int		ft_toupper(int a);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strdup(const char *src);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif