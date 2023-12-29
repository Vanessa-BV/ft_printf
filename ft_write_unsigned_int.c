/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_unsigned_int.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/20 12:27:10 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/12/29 14:37:55 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nb_len(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_uitoa(unsigned int n)
{
	char			*str;
	int				index;
	int				len;

	len = ft_nb_len(n);
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (str == NULL)
		return (-1);
	index = len - 1;
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[index--] = (n % 10) + '0';
		n /= 10;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

