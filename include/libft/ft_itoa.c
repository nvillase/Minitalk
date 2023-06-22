/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:00:13 by nvillase          #+#    #+#             */
/*   Updated: 2023/02/23 15:43:24 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbr_len(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len_n;
	char	*mal;
	long	c;

	c = n;
	len_n = nbr_len(c);
	mal = (char *)malloc((len_n + 1) * sizeof(char));
	if (!mal)
		return (NULL);
	mal[len_n] = '\0';
	if (c < 0)
	{
		mal[0] = '-';
		c *= -1;
	}
	if (c == 0)
		mal[0] = '0';
	while (c != 0)
	{
		len_n--;
		mal[len_n] = c % 10 + '0';
		c /= 10;
	}
	return (mal);
}
