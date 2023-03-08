/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:21:49 by srachdi           #+#    #+#             */
/*   Updated: 2023/01/01 16:57:23 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*extractline(char *storage)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!*storage)
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i += 1;
	str = (char *)malloc(sizeof (char) * (i + 1));
	if (!str)
		return (NULL);
	while (storage[j] && j < i)
	{
		str[j] = storage[j];
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*resetstorage(char *storage)
{
	int		i;
	int		j;
	char	*newstorage;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	if (storage[i] == '\n')
		i += 1;
	newstorage = malloc((ft_strlen(storage) - i + 1) * sizeof(char));
	if (!newstorage)
		return (NULL);
	j = 0;
	while (storage[i])
		newstorage[j++] = storage[i++];
	newstorage[j] = '\0';
	free(storage);
	return (newstorage);
}

char	*readandstore(int fd, char *storage)
{
	int		readlen;
	char	*readstr;

	readstr = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!readstr)
		return (NULL);
	readlen = 1;
	while (!ft_strchr(storage, '\n') && readlen != 0)
	{
		readlen = read(fd, readstr, BUFFER_SIZE);
		if (readlen == -1)
		{
			free(storage);
			free (readstr);
			return (NULL);
		}
		readstr[readlen] = '\0';
		storage = ft_strjoin(storage, readstr);
	}
	free (readstr);
	return (storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = readandstore(fd, storage);
	if (!storage)
		return (NULL);
	line = extractline(storage);
	storage = resetstorage(storage);
	return (line);
}
