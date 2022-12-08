/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:51:42 by hrobin            #+#    #+#             */
/*   Updated: 2022/12/06 19:09:00 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_ptr_hexa_len(unsigned long int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_ptr_hexa(unsigned long int num)
{
	if (num >= 16)
	{
		ft_ptr_hexa(num / 16);
		ft_ptr_hexa(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_put_ptr_hexa(unsigned long ptr)
{
	int	print_length;

	print_length = 0;
	if (ptr == 0)
		print_length += write (1, "(nil)", 5);
	else
	{
		print_length += write(1, "0x", 2);
		ft_ptr_hexa(ptr);
		print_length += ft_ptr_hexa_len(ptr);
	}
	return (print_length);
}
