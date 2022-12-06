/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:45:34 by hrobin            #+#    #+#             */
/*   Updated: 2022/12/06 18:19:03 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
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

int	ft_hex(unsigned long num, const char mode)
{
	int	maj;
	const char	*base = "0123456789abcdef";
	const char	*base_up = "0123456789ABCDEF";	
	maj = 0;
	if (mode == 'p')
		write(1, "0x", 2);
	if (mode == 'X')
		maj = 16;
	if (num >= 16)
	{
		ft_hex(num / 16, mode);
		ft_hex(num % 16, mode);
	}
	else
	{

		if (maj)
			write(1, &base[num], 1);
		else
			write(1, &base_up[num], 1);
	}
	return (0);
}

int	ft_print_hex(unsigned long num, const char mode)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_hex(num, mode);
	return (ft_hexa_len(num));
}

int main ()
{
	unsigned long	num;
	char	mode;

	num = -1;
	mode = 'x';
	printf("%x\n", -1);
	ft_print_hex(num, mode);
}
