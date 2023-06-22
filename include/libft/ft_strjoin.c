/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:27:14 by nvillase          #+#    #+#             */
/*   Updated: 2023/02/21 16:28:17 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*t;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	t = (char *)malloc(s1_len + s2_len + 1);
	if (!t)
		return (NULL);
	ft_memcpy(t, s1, s1_len);
	ft_memcpy(t + s1_len, s2, s2_len);
	t[s1_len + s2_len] = '\0';
	return (t);
}
