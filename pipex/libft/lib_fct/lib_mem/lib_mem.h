/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_mem.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:54:48 by eslamber          #+#    #+#             */
/*   Updated: 2022/12/14 15:00:44 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MEM_H
# define LIB_MEM_H
# include <stdlib.h>
# include <stdint.h>

// Set the n first bytes at c in the memorie pointed by s
void	*ft_memset(void *s, int c, size_t n);

// Same as memset with 0
// Return nothing
void	ft_bzero(void *s, size_t n);

// Copy n first bytes of src memorie to dest memorie
void	*ft_memcpy(void *dest, const void *src, size_t n);

// Copy n first bytes of src to dest with a temporarie stocking
void	*ft_memmove(void *dest, const void *src, size_t n);

// Return first occurence of c in src
void	*ft_memchr(const void *src, int c, size_t n);

// Return difference (s - c) when differents
int		ft_memcmp(const void *s, const void *c, size_t n);

// Same as malloc but fill with 0
void	*ft_calloc(size_t nbr, size_t size);
#endif
