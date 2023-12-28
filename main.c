/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbusekru <vbusekru@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/20 11:47:03 by vbusekru      #+#    #+#                 */
/*   Updated: 2023/12/28 12:28:17 by vbusekru      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int		result;
	int		printf_result;

	result = ft_printf("%s", "some string with %s hehe");
	printf("My version: %d\n", result);
	printf_result = printf("%s", "some string with %s hehe");
	printf("Original: %d\n", printf_result);
	if (result == printf_result)
		printf("Outputs match!\n");
	else
		printf("Outputs do not match.\n");
	return (0);
}

// int	main(void)
// {
// 	int		result;
// 	int		printf_result;
// 	char	*tmp = NULL;

// 	result = ft_printf(" NULL %s NULL \n", tmp);
// 	printf("My version: %d\n", result);
// 	printf_result = printf(" NULL %s NULL \n", tmp);
// 	printf("Original: %d\n", printf_result);
//     if (result == printf_result) {
//         printf("Outputs match!\n");
//     } else {
//         printf("Outputs do not match.\n");
//     }
// 	return (0);
// }