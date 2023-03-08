/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:23:34 by srachdi           #+#    #+#             */
/*   Updated: 2023/01/03 04:34:38 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkstrangechar(char *str1, char *str2)
{
	int	i;
	int	exists;
	int	j;

	i = 0;
	while (i < (int)ft_strlen(str1))
	{
		exists = 0;
		j = 0;
		while (j < (int)ft_strlen(str2))
		{
			if (str1[i] == str2[j])
			{
				exists = 1;
				break ;
			}
			j++;
		}
		if (!exists)
			return (1);
		i++;
	}
	return (0);
}

int	checkmapstring(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_string[i] != '\0')
	{
		if (game->map_string[i] == 'P')
			game->player_count++;
		if (game->map_string[i] == 'E')
			game->exit_count++;
		if (game->map_string[i] == 'C')
			game->all_collect++;
		i++;
	}
	if (game->player_count != 1 || game->exit_count != 1
		|| game->all_collect < 1)
		return (1);
	return (0);
}

int	isber(char *filename)
{
	int	filenamelen;

	filenamelen = ft_strlen(filename);
	if (ft_strcmp (filename + (filenamelen - 4), ".ber"))
		return (0);
	else
		return (1);
}

int	checkwalls(t_game *game)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(game->map_string))
	{
		if (i < game->width)
			if (game->map_string[i] != '1')
				return (0);
		if (i % game->width == 0)
			if (game->map_string[i] != '1'
				|| game->map_string[i + game->width - 1] != '1')
				return (0);
		if (i > (int)ft_strlen(game->map_string) - game->width)
			if (game->map_string[i] != '1')
				return (0);
		i++;
	}
	return (1);
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
