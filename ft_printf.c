/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:22:40 by hrobin            #+#    #+#             */
/*   Updated: 2022/12/06 17:50:24 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdint.h>


int	ft_formats(va_list args, const char format)
{
	int	result;

	result = 0;
	if (format == 'c')
		result = ft_putchar(va_arg(args, int));
	if (format == 's')
		result = ft_printstr(va_arg(args, char *));
	if (format == 'p')
		result = ft_print_hex(va_arg(args, uintptr_t), format);
	if (format == 'd')
		result = ft_print_nbr(va_arg(args, int), format);
	if (format == 'i')
		result = ft_print_nbr(va_arg(args, int), format);
	if (format == 'u')
		result = ft_print_nbr(va_arg(args, unsigned int), format);
	if (format == 'x')
		result = ft_print_hex(va_arg(args, unsigned int), format);
	if (format == 'X')
		result = ft_print_hex(va_arg(args, unsigned int), format);
	if (format == '%')
		result = ft_percent();
	return (result);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	va_list	args;
	int printed;

	i = 0;
	printed = 0;
	va_start(args, str);

	while (str[i])
	{
		if (str[i] == '%')
		{
			printed += ft_formats(args, str[i + 1]);
			i += 2;
		}
		else
		{
			ft_putchar(str[i]);
			i++;
			printed++;
		}
	}
	va_end(args);
	return (printed);
}

/*
int main ()
{
	const char *str;

	str = "bonjour %d %s \n";
	ft_printf(str, 7, "prout");
}
*/
