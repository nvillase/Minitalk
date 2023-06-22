/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:38:28 by nvillase          #+#    #+#             */
/*   Updated: 2023/02/21 16:38:32 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	debut;
	size_t	len;

	debut = 0;
	len = ft_strlen(s1);
	while (debut < len && ft_strchr(set, s1[debut]) != NULL)
		debut++;
	while (len > debut && ft_strchr(set, s1[len - 1]) != NULL)
		len--;
	s2 = (char *)malloc(sizeof(char) * (len - debut + 1));
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s1 + debut, len - debut);
	s2[len - debut] = '\0';
	return (s2);
}
