/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <hrobin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:45:34 by hrobin            #+#    #+#             */
/*   Updated: 2023/02/06 15:08:24 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_hexa_len(unsigned long num)
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

void	ft_hex(unsigned long num, const char mode)
{
	if (num >= 16)
	{
		ft_hex(num / 16, mode);
		ft_hex(num % 16, mode);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (mode == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (mode == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned long num, const char mode)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_hex(num, mode);
	return (ft_hexa_len(num));
}

/*
int main ()
{
	unsigned long	num;
	char	mode;

	num = -1;
	mode = 'x';
	printf("%x\n", -1);
	ft_print_hex(num, mode);
}
*/
