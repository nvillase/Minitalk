/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foction_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:26:50 by nvillase          #+#    #+#             */
/*   Updated: 2023/03/13 11:51:24 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write (1, "(null)", 6));
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		count++;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count + 1);
}

int	ft_printnbr(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count + 1);
}

int	ft_putexxx(unsigned long nb, char format)
{
	int		count;
	char	*base;
	char	*basebig;

	count = 0;
	base = "0123456789abcdef";
	basebig = "0123456789ABCDEF";
	if (nb >= 16)
	{
		ft_putexxx(nb / 16, format);
		ft_putexxx(nb % 16, format);
	}
	else
	{
		if (format == 'x')
			ft_putchar(base[nb]);
		else if (format == 'X')
			ft_putchar(basebig[nb]);
	}
	while (nb >= 16)
	{
		nb /= 16;
		count++;
	}
	return (count + 1);
}
