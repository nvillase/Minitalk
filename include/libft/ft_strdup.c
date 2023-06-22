/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:43:36 by nvillase          #+#    #+#             */
/*   Updated: 2023/06/08 17:31:58 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;
	int		i;

	if (!s1)
		return (NULL);
	i = -1;
	len = ft_strlen(s1);
	s2 = (char *) malloc((len + 1) * sizeof(char));
	while (s1[++i])
		s2[i] = s1[i];
	s2[len] = '\0';
	return (s2);
}
