/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvillase <nvillase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:30:44 by nvillase          #+#    #+#             */
/*   Updated: 2023/06/08 17:31:32 by nvillase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*zip[1024];
	int			i;

	i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(zip[fd]), zip[fd] = NULL);
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		buffer[i] = '\0';
		zip[fd] = ft_strjoinprime(zip[fd], buffer);
		if (ft_strpchr(zip[fd]))
			break ;
	}
	free(buffer);
	return (print_line(&zip[fd]));
}

char	*ft_strwdup(char *s1, int w)
{
	char	*s2;
	int		count;

	count = -1;
	if (!s1 || !w)
		return (NULL);
	s2 = (char *)malloc(w * sizeof(char) + 1);
	while (++count < w)
		s2[count] = s1[count];
	s2[count] = '\0';
	return (s2);
}
