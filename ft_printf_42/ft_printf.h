/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaule <dbaule@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:26:21 by dbaule            #+#    #+#             */
/*   Updated: 2022/11/23 21:30:35 by dbaule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printchar(int c);
int	ft_printstr(char *c);
int	ft_printint(int d);
int	ft_printunsignedint(unsigned int u);
int	ft_printhexamin(int a);
int	ft_printhexamaj(int b);
int	ft_printaddress(unsigned long long a);
int	ft_printf(const char *s, ...);

#endif