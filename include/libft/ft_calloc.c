/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:06:36 by nvillase          #+#    #+#             */
/*   Updated: 2023/02/20 08:33:44 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	jcc;
	char	*loufoque;

	if (!nmemb || !size)
		return (malloc(0));
	jcc = nmemb * size;
	if (jcc / nmemb != size || jcc / size != nmemb)
		return (NULL);
	loufoque = malloc(jcc);
	if (!loufoque)
		return (NULL);
	ft_bzero(loufoque, jcc);
	return (loufoque);
}
