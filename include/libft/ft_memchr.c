/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:22:19 by nvillase          #+#    #+#             */
/*   Updated: 2023/02/14 16:53:14 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*p;
	size_t		i;

	i = 0;
	p = s;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (p[i] == (char)c)
			return ((void *)&p[i]);
		i++;
	}
	return (NULL);
}
