/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:30:39 by nvillase          #+#    #+#             */
/*   Updated: 2023/03/28 11:03:16 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinprime(char *s1, char *s2)
{
	char	*array;
	size_t	s1_len;
	size_t	s2_len;
	int		i;
	int		b;

	i = -1;
	b = -1;
	if (!s1)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	array = (char *)malloc(s1_len + s2_len + 1);
	if (!array)
		return (NULL);
	while (s1[++i])
		array[i] = s1[i];
	while (s2[++b])
		array[i++] = s2[b];
	array[i] = '\0';
	free(s1);
	return (array);
}

int	ft_strpchr(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	if (s[i] == '\n')
		return (1);
	return (0);
}

char	*print_line(char **s1)
{
	int		i;
	char	*line;
	char	*str;

	if (!*s1)
		return (NULL);
	str = *s1;
	i = 0;
	while (str[i] && str[i] != 10)
		i++;
	if (str[i] == 10)
		i++;
	line = ft_strwdup(str, i);
	*s1 = ft_strwdup(str + i, ft_strlen(str + i));
	free(str);
	return (line);
}
