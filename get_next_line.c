/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:02:28 by imabid            #+#    #+#             */
/*   Updated: 2021/11/22 12:15:34 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffer(int fd, char *str)
{
	char	*buff;
	int		r;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	r = 1;
	while (!ft_strchr(str, '\n') && r)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[r] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

char	*get_line(char *s)
{
	char	*line;
	int		i;

	i = 0;
	if (!s[0])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_newrest(char *s)
{
	char	*new_rest;
	int		i;
	int		lens;
	int		j;

	j = 0;
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	lens = ft_strlen(&s[i + 1]) + 1;
	new_rest = (char *)malloc(sizeof(char) * lens);
	if (!new_rest)
		return (NULL);
	i++;
	while (s[i])
		new_rest[j++] = s[i++];
	new_rest[j] = '\0';
	free (s);
	return (new_rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = read_buffer(fd, rest);
	if (!rest)
		return (NULL);
	line = get_line(rest);
	rest = get_newrest(rest);
	return (line);
}
