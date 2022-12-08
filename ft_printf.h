/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:20:02 by hrobin            #+#    #+#             */
/*   Updated: 2022/12/08 15:29:36 by hrobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>  

int	ft_hexa_len(unsigned long num);
void	ft_hex(unsigned long num, const char mode);
int	ft_print_hex(unsigned long num, const char mode);
int	ft_percent(void);
int	ft_putchar(char c);
int	ft_num_len(unsigned int num);
char	*ft_uns_itoa(unsigned int n);
int	ft_put_uns_nbr(unsigned int n);
void	ft_putchar_fd(char c, int fd);
int	ft_putnbr_len(long num);
int	ft_putnbr(int n);
void	ft_bzero(void *s, size_t n);
void	ft_condition(long nb, int i, char *itoa);
char	*ft_itoa(int n);
int     ft_print_nbr(long num, const char format);
int 	ft_putstr(char *str);
int	ft_printstr(char *str);
int     ft_ptr_hexa_len(unsigned long int num);
void    ft_ptr_hexa(unsigned long int num);
int     ft_put_ptr_hexa(unsigned long ptr);
int     ft_printf(const char *str, ...);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

#endif
