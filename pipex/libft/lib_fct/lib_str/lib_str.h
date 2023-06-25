/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_str.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:06:15 by eslamber          #+#    #+#             */
/*   Updated: 2023/01/11 13:49:24 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_STR_H
# define LIB_STR_H
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>
# include "get_next_line.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Return 1 if src is in test
int		ft_in(const char src, const char *test);

// Return 1 if c is alphabethic caractere
int		ft_isalpha(int c);

// Return 1 if c is a numeric caractere
int		ft_isdigit(int c);

// Return 1 if c is a alphabethic or numeric caractere
int		ft_isalnum(int c);

// Return 1 if c is an ascii caractere
int		ft_isascii(int c);

// Return 1 if c is a printable caractere
int		ft_isprint(int c);

// Return size of string passed
size_t	ft_strlen(const char *s);

// Copy n - 1 first caracteres from src to dest
size_t	ft_strlcpy(char *dest, const char *src, size_t n);

// Concatenate src at end of dest
size_t	ft_strlcat(char *dest, const char *src, size_t n);

// Return upper caractere of c if is a lowercase caractere
int		ft_toupper(int c);

// Return lower caractere of c if is a uppercase caractere
int		ft_tolower(int c);

// Return first occurence of c in the string s, 0 if not found
char	*ft_strchr(const char *s, int c);

// Return last occurence of c in the string s, 0 if not found
char	*ft_strrchr(const char *s, int c);

// Return negative number if first is less than sec, positive if sec is greater
// than first, and 0 if they are same
int		ft_strncmp(const char *first, const char *sec, size_t n);

// Return first occurence of little
char	*ft_strnstr(const char *big, const char *little, size_t n);

// Change int string to int
int		ft_atoi(const char *s);

// Duplicate string in another string allocated
char	*ft_strdup(const char *src);

// Copy len caracteres from s[start]
// Return this new string or 0 if didn't work
char	*ft_substr(const char *s, unsigned int start, size_t len);

// Return new string what is src concatenated to dest
char	*ft_strjoin(const char *dest, const char *src);

// Return a new string src without caracteres in set
char	*ft_strtrim(const char *src, const char *set);

// Return a new string src without caracteres in set
char	**ft_split(const char *src, char set);

// Inverse of atoi
char	*ft_itoa(int n);

// Duplicate str and affect f on each caracteres of new string
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));

// Affect the fontion f for each caracteres
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

// Function ft_calloc used for lib_str
void	*ft_calloc_str(size_t nbr, size_t size);

// Give the first line of file fd
char	*get_next_line(int fd);
#endif
