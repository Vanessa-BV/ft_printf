/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_hexa.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/20 12:23:01 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/12/29 15:44:16 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexnb_len(unsigned long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_hexitoa(unsigned int n, const char c)
{
	char			*str;
	unsigned int	hex_len;
	char			*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (n == 0)
		return(ft_write_char('0'));
	hex_len = ft_hexnb_len(n);
	str = (char *)ft_calloc((hex_len + 1), sizeof(char));
	if (str == NULL)
		return (-1);
	while (n > 0)
	{
		str[--hex_len] = base[n % 16];
		n = n / 16;
	}
	hex_len = ft_write_str(str);
	free(str);
	return (hex_len);
}

int	ft_ptr_itoa(unsigned long n)
{
	char			*str;
	unsigned long	ptr_len;
	const char		*base;

	base = "0123456789abcdef";
	if (n == 0)
		return (ft_write_str("0x0")); //should be "nil"?
	else
	{
		ptr_len = ft_hexnb_len(n);
		str = (char *)ft_calloc((ptr_len + 1), sizeof(char));
		if (str == NULL)
			return (ft_write_str("nil")); //not sure! 
		while (n > 0)
		{
			str[--ptr_len] = base[n % 16];
			n = n / 16;
		}
		ft_write_str("0x");
		ptr_len = (ft_write_str(str) + 2);
		free(str);
		return (ptr_len);
	}
}