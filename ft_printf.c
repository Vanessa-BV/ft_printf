/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/20 11:50:58 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/12/20 13:51:52 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(const char *str, va_list args)
{
	int		count;

	count = 0;
	if (*str == 'c')
		count = ft_write_char(va_arg(args, int));
	else if (*str == 's')
		count = ft_write_str(va_arg(args, char *));
	else if (*str == 'd' || *str == 'i')
		count = ft_write_int(va_arg(args, int));
	else if (*str == 'p')
		count = ft_write_ptr(va_arg(args, void *));
	else if (*str == 'x' || *str == 'X')
		count = ft_write_hexa(va_arg(args, int), *str);
	else if (*str == 'u')
		count = ft_write_unsigned_int(va_arg(args, unsigned int));
	else if (*str == '%')
		count = ft_write_char('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	args;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c' || str[i] == 's' || str[i] == 'd' || str[i] == 'i'
				|| str[i] == 'p' || str[i] == 'x' || str[i] == 'X'
				|| str[i] == 'u' || str[i] == '%')
				count += ft_formats(&str[i], args);
		}
		else
			count += ft_write_char(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
