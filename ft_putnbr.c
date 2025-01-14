/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hortense <hortense@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:09:16 by hrobin            #+#    #+#             */
/*   Updated: 2025/01/14 12:07:44 by hortense         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zero(void *s, int n)
{
	char	*c;
	int	i;

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
	ft_zero(itoa, i);
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
