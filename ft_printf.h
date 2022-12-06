/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:20:02 by hrobin            #+#    #+#             */
/*   Updated: 2022/12/06 17:51:03 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>   

int	ft_hexa_len(unsigned long num);
int	ft_hex(unsigned long num, const char mode);
int	ft_print_hex(unsigned long num, const char mode);
int	ft_percent(void);
int	ft_putchar(char c);
int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_len(long num);
void	ft_putnbr(long num, const char format);
int     ft_print_nbr(long num, const char format);
int 	ft_putstr(char *str);
int	ft_printstr(char *str);
int     ft_printf(const char *str, ...);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

#endif
