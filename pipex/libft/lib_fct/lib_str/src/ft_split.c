/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:39:07 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/25 14:26:54 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib_str.h"

static int	check_char(char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] == c && s[len] != '\0')
		len++;
	if (s[len] == '\0')
		return (0);
	return (1);
}

static size_t	analyse(char *s, char c, size_t *len)
{
	size_t	nbr;
	size_t	ind;

	*len = 0;
	if (ft_strncmp(s, "", ft_strlen(s)) == 0 || check_char(s, c) == 0)
		nbr = 0;
	else
		nbr = 1;
	while (s[*len] != '\0')
	{
		if (s[*len] == c)
			s[*len] = '\0';
		if (*len != 0 && s[*len] == '\0' && s[*len - 1] != '\0')
		{
			ind = *len + 1;
			while (s[ind] == c)
				ind++;
			if (s[ind] != '\0')
				nbr++;
		}
		(*len)++;
	}
	return (nbr);
}

static void	annihilation(char **new, char *s)
{
	size_t	len;

	len = 0;
	while (new[len])
		free(new[len++]);
	free(s);
	free(new);
}

static int	const_new(char **new, char *s, size_t *len_n, size_t *nbr_w)
{
	if ((*len_n == 0 && s[*len_n] != '\0') \
			|| (*len_n != 0 && s[(*len_n) - 1] == '\0' && s[*len_n] != '\0'))
	{
		new[*nbr_w] = ft_strdup(&s[*len_n]);
		if (new[*nbr_w] == 0)
		{
			annihilation(new, s);
			return (0);
		}
		*nbr_w = *nbr_w + 1;
	}
	*len_n = *len_n + 1;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	size_t	len;
	size_t	len_new;
	size_t	nbr_word;
	char	**new;
	char	*src;

	len_new = 0;
	src = ft_strdup(s);
	if (src == 0)
		return (0);
	nbr_word = analyse(src, c, &len);
	new = ft_calloc_str(nbr_word + 1, sizeof(char *));
	if (new == 0)
	{
		free(src);
		return (0);
	}
	nbr_word = 0;
	while (len_new < len)
		if (const_new(new, src, &len_new, &nbr_word) == 0)
			return (0);
	free(src);
	return (new);
}
