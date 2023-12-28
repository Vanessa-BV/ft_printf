/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_ptr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/20 12:17:59 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/12/28 12:05:30 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_ptr_hexadecimals(uintptr_t n)
{
	int	len;

	len = 0;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_pointer_itoa(uintptr_t n)
{
	char			*str;
	int				index;
	int				int_size;
	uintptr_t		numb;
	const char		*base;

	base = "0123456789abcdef";
	numb = n;
	int_size = ft_count_ptr_hexadecimals(numb);
	str = (char *)ft_calloc((int_size + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	index = int_size - 1;
	if (numb == 0)
		str[0] = '0';
	while (numb > 0)
	{
		str[index--] = base[numb % 16];
		numb /= 16;
	}
	return (str);
}

int	ft_write_ptr(void *ptr)
{
	int			count;
	char		*str;
	char		*address_start;
	uintptr_t	n;

	count = 0;
	address_start = "0x";
	n = (uintptr_t)ptr;
	if (n == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	str = ft_pointer_itoa(n);
	if (str == NULL)
	{
		write(1, "nil", 3);
		return (3);
	}
	write(1, address_start, 2);
	ft_putstr_fd(str, 1);
	count = (ft_strlen(str) + 2);
	free(str);
	return (count);
}
