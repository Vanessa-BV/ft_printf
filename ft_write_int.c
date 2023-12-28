/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_int.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/20 12:02:12 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/12/28 12:27:58 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_int(int n)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_itoa(n);
	if (str == NULL)
		return (0);
	count = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (count);
}
