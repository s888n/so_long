/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:22:48 by srachdi           #+#    #+#             */
/*   Updated: 2023/01/03 04:32:43 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exitmap(t_game *game, char *message)
{
	free (game->map_string);
	free (game);
	exiterror (message);
}

void	checkmap(t_game *game)
{
	if (checkmapstring (game))
		exitmap (game, "map must contain :"
			"1 player,1 exit,and at least one collectible");
	if (checkstrangechar (game->map_string, "01PEC"))
		exitmap (game, "Strange char detected in the map file");
	if ((game->width * game->height) != (int)ft_strlen (game->map_string))
		exitmap (game, "Map is not rectangular");
	if (!checkwalls (game))
		exitmap (game, "Map is not sorounded by walls");
	if (!validpath (game))
		exitmap (game, "no valid path in the map");
}

char	*readmap(char *filename, t_game *game)
{
	int		fd;
	char	*s;
	char	*line;

	fd = open (filename, O_RDONLY);
	if (fd < 0)
		exiterror ("couldn't open file");
	s = NULL;
	line = get_next_line(fd);
	if (!line)
		exiterror("map file is empty or corrupted :(");
	game->width = ft_strlen_n(line);
	game->height = 0;
	while (line)
	{
		s = ft_strjoin_n(s, line);
		free(line);
		line = get_next_line(fd);
		game->height++;
	}
	close (fd);
	free (line);
	return (s);
}
