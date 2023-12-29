/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/20 11:50:58 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/12/29 15:28:18 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(const char *str, va_list args)
{
	int		count;

	count = 0;
	if (*str == '\0')
		return (-1);
	else if (*str == 'c')
		count += ft_write_char(va_arg(args, int));
	else if (*str == 's')
		count += ft_write_str(va_arg(args, char *));
	else if (*str == 'd' || *str == 'i')
		count += ft_write_int(va_arg(args, int));
	else if (*str == 'p')
		count += ft_ptr_itoa(va_arg(args, unsigned long));
	else if (*str == 'x' || *str == 'X')
		count += ft_hexitoa(va_arg(args, int), *str);
	else if (*str == 'u')
		count += ft_uitoa(va_arg(args, unsigned int));
	else if (*str == '%')
		count += ft_write_char('%');
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		n;
	va_list	args;

	count = 0;
	if (str == NULL)
		return (0);
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			n = ft_formats(str, args);
			if (n > -1)
				count = count + n;
			else
				return (-1);
		}
		else
			count += ft_write_char(*str);
		str++;
	}
	va_end(args);
	return (count);
}
