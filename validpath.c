/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:23:43 by srachdi           #+#    #+#             */
/*   Updated: 2023/01/01 18:40:58 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	isvalid(t_maze *maze, int i, int j)
{
	return (i >= 0 && i < maze->height && j >= 0
		&& j < maze->width && maze->visited[i][j] == 0 &&
		maze->m[i][j] != '1');
}

int	search(t_maze *maze, int i, int j)
{
	maze->visited[i][j] = 1;
	if (maze->m[i][j] == 'E')
		return (1);
	else if (isvalid(maze, i + 1, j) && search(maze, i + 1, j))
		return (1);
	else if (isvalid(maze, i, j + 1) && search(maze, i, j + 1))
		return (1);
	else if (isvalid(maze, i - 1, j) && search(maze, i - 1, j))
		return (1);
	else if (isvalid(maze, i, j - 1) && search(maze, i, j - 1))
		return (1);
	return (0);
}

void	init_maze(t_maze *maze, t_game *game)
{
	int		i;
	int		j;
	char	*s;

	s = game->map_string;
	maze->height = game->height;
	maze->width = game->width;
	i = 0;
	while (i < maze->height && *s)
	{
		j = 0;
		while (j < maze->width && *s)
		{
			maze->m[i][j] = *s;
			maze->visited[i][j] = 0;
			j++;
			s++;
		}
		i++;
	}
}

int	validpath(t_game *game)
{
	int		i;
	int		j;
	t_maze	maze;

	init_maze(&maze, game);
	i = 0;
	while (i < maze.height)
	{
		j = 0;
		while (j < maze.width)
		{
			if (maze.m[i][j] == 'P')
				break ;
			j++;
		}
		if (maze.m[i][j] == 'P')
			break ;
		i++;
	}
	if (search(&maze, i, j))
		return (1);
	else
		return (0);
}
