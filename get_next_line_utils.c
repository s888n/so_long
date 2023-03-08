/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:22:12 by srachdi           #+#    #+#             */
/*   Updated: 2023/01/01 16:57:44 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

int	ft_strchr(char *str, int c)
{
	if (!str)
		return (0);
	while (*str && *str != (char)c)
		str++;
	if (*str == (char)c)
		return (1);
	return (0);
}

char	*ft_strjoin(char *storage, char *readstr)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!storage)
	{
		storage = (char *)malloc(1 * sizeof(char));
		storage[0] = '\0';
	}
	if (!storage || !readstr)
		return (NULL);
	i = ft_strlen(storage) + ft_strlen(readstr);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (storage)
		while (storage[++i] != '\0')
			str[i] = storage[i];
	while (readstr[j] != '\0')
		str[i++] = readstr[j++];
	str[ft_strlen(storage) + ft_strlen(readstr)] = '\0';
	free(storage);
	return (str);
}
