/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_unsigned_int.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/20 12:27:10 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/12/28 12:27:32 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_unsigned_digit(unsigned int n)
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

char	*ft_unsigned_itoa(unsigned int n)
{
	char			*str;
	int				index;
	int				int_size;
	unsigned int	numb;

	numb = n;
	int_size = ft_count_unsigned_digit(numb);
	str = (char *)ft_calloc((int_size + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	index = int_size - 1;
	if (numb == 0)
		str[0] = '0';
	while (numb > 0)
	{
		str[index--] = (numb % 10) + '0';
		numb /= 10;
	}
	return (str);
}

int	ft_write_unsigned_int(unsigned int n)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_unsigned_itoa(n);
	if (str == NULL)
		return (0);
	count = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (count);
}
