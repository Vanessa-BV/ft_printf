/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_str.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/20 12:01:30 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/12/28 12:27:42 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_str(char *str)
{
	int		count;

	count = 0;
	if (str == NULL)
		str = "(null)";
	ft_putstr_fd(str, 1);
	count = ft_strlen(str);
	return (count);
}
