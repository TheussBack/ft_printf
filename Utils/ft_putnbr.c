/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:09:16 by hrobin            #+#    #+#             */
/*   Updated: 2022/12/08 15:33:49 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	char	*c;
	size_t	i;

	c = (char *)s;
	i = 0;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}

void	ft_condition(long nb, int i, char *itoa)
{
	if (nb < 0)
	{
		itoa[0] = '-';
		nb *= -1;
	}
	itoa[i] = '\0';
	while (--i >= 0 && itoa[i] != '-')
	{
		itoa[i] = (nb % 10) + 48;
		nb /= 10;
	}
}

char	*ft_itoa(int n)
{
	long	nb;
	int		i;
	char	*itoa;

	nb = n;
	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	itoa = malloc(sizeof(char) * (i + 1));
	if (!itoa)
		return (NULL);
	ft_bzero(itoa, i);
	ft_condition(nb, i, itoa);
	return (itoa);
}

int	ft_putnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_printstr(num);
	free(num);
	return (len);
}
/*
#include "../ft_printf.h"

int     ft_putnbr_len(long num)
{
        int i;

        i = 0;
        while (num != 0)
        {
                i++;
                num = num / 10;
        }
        return (i);
}

void     ft_putnbr(long num, const char format)
{
        if (num < 0)
        {
                num *= - 1;
                write(1, "-", 1);
        }
        if (num > 10)
        {
                ft_putnbr(num / 10, format);
                ft_putnbr(num % 10, format);
        }
        else
                ft_putchar(num + '0');
}

int     ft_print_nbr(long num, const char format)
{
        if (num == 0)
                return (write(1, "0", 1));
        else 
                ft_putnbr(num, format);
        return (ft_putnbr_len(num));
}

int     main()
{
        long    num;
        const char      format;

        num = -1;
        (void)format;
        ft_putnbr(num, format);
}
*/