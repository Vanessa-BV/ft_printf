/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/02 10:15:14 by vbusekru      #+#    #+#                 */
/*   Updated: 2024/01/02 10:15:14 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_formats(const char *str, va_list args);
int		ft_write_char(int c);
int		ft_write_str(char *str);
int		ft_write_int(int n);
int		ft_ptr_itoa(unsigned long n);
int		ft_hexitoa(unsigned int n, const char c);
int		ft_hexnb_len(unsigned long n);
int		ft_uitoa(unsigned int n);
int		ft_nb_len(unsigned int n);
#endif