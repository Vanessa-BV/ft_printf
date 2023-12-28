/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/07 12:01:59 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/12/28 12:27:11 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		ft_formats(const char *str, va_list args);
int		ft_write_char(int c);
int		ft_write_str(char *str);
int		ft_write_int(int n);
int		ft_write_ptr(void *ptr);
char	*ft_pointer_itoa(uintptr_t n);
int		ft_count_ptr_hexadecimals(uintptr_t n);
int		ft_write_hexa(int n, char c);
char	*ft_hexadecimal_itoa(unsigned int n);
int		ft_count_hexadecimals(unsigned int n);
int		ft_write_unsigned_int(unsigned int n);
char	*ft_unsigned_itoa(unsigned int n);
int		ft_count_unsigned_digit(unsigned int n);
#endif