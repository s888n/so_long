/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:13:23 by srachdi           #+#    #+#             */
/*   Updated: 2023/01/03 01:13:28 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	ft_strlen_n(char *s)
{
	size_t	c;

	c = 0;
	while (*s != '\0' && *s != '\n' && *s)
	{
		s++;
		c++;
	}
	return (c);
}

char	*ft_strjoin_n(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen_n(s1) + ft_strlen_n(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0' && s1[i] != '\n')
		str[i] = s1[i];
	while (s2[j] != '\0' && s2[j] != '\n')
		str[i++] = s2[j++];
	str[i] = '\0';
	free (s1);
	return (str);
}

void	checkfile(int ac, char *av)
{
	if (ac < 2)
		exiterror("too few arguments");
	if (ac > 2)
		exiterror("too many arguments");
	if (!isber(av))
		exiterror("file is not in ber format");
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
