/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:44:34 by nvillase          #+#    #+#             */
/*   Updated: 2023/02/13 16:03:51 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	srcsize;
	size_t	destsize;

	i = 0;
	srcsize = ft_strlen(src);
	destsize = ft_strlen(dest);
	if ((!dest || !src) && size == 0)
		return (0);
	if (size <= destsize)
		return (size + srcsize);
	while (src[i] && (i + destsize) < size - 1)
	{
		dest[destsize + i] = src[i];
		i++;
	}
	dest[destsize + i] = 0;
	return (srcsize + destsize);
}
