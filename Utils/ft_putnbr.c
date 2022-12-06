/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:09:16 by hrobin            #+#    #+#             */
/*   Updated: 2022/12/06 17:30:40 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/*
int     main()
{
        long    num;
        const char      format;

        num = 1200000;
        (void)format;
        ft_putnbr(num, format);
}
*/
