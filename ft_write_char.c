/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_write_char.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/20 12:00:48 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/12/28 12:27:38 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
