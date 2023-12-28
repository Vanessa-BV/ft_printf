/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_hexa.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/20 12:23:01 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/12/28 12:25:33 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_hexadecimals(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_hexadecimal_itoa(unsigned int n)
{
	char			*str;
	int				index;
	int				int_size;
	unsigned int	numb;
	const char		*base;

	base = "0123456789abcdef";
	numb = n;
	int_size = ft_count_hexadecimals(numb);
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

int	ft_write_hexa(int n, char c)
{
	int				count;
	int				i;
	char			*string;
	unsigned int	un;

	i = 0;
	count = 0;
	un = (unsigned int)n;
	string = ft_hexadecimal_itoa(un);
	if (string == NULL)
		return (0);
	if (c == 'X')
	{
		while (string[i] != '\0')
		{
			string[i] = ft_toupper(string[i]);
			i++;
		}
	}
	count = ft_strlen(string);
	ft_putstr_fd(string, 1);
	free(string);
	return (count);
}
