/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:22:25 by srachdi           #+#    #+#             */
/*   Updated: 2023/01/01 16:22:09 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loadimages(t_game *game)
{
	int	height;
	int	width;

	game->image.wall = mlx_xpm_file_to_image(game->mlx,
			"./textures/wall.xpm", &width, &height);
	game->image.ground = mlx_xpm_file_to_image(game->mlx,
			"./textures/ground.xpm", &width, &height);
	game->image.player_right = mlx_xpm_file_to_image(game->mlx,
			"./textures/gR.xpm", &width, &height);
	game->image.player_left = mlx_xpm_file_to_image(game->mlx,
			"./textures/gL.xpm", &width, &height);
	game->image.gate_closed = mlx_xpm_file_to_image(game->mlx,
			"./textures/gateC.xpm", &width, &height);
	game->image.gate_open = mlx_xpm_file_to_image(game->mlx,
			"./textures/gateO.xpm", &width, &height);
	game->image.collectible = mlx_xpm_file_to_image(game->mlx,
			"./textures/chest.xpm", &width, &height);
	if (!game->image.wall || !game->image.ground || !game->image.player_left
		||!game->image.player_right ||!game->image.gate_closed
		||!game->image.gate_open || !game->image.collectible)
	{
		write(2, "could'nt load image", 20);
		exitgame(game);
	}
}

void	putimage(t_game *game, int w, int h)
{
	if (game->map_string[h * game->width + w] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->image.wall, w * IMAGE_SIZE, h * IMAGE_SIZE);
	else
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->image.ground, w * IMAGE_SIZE, h * IMAGE_SIZE);
		if (game->map_string[h * game->width + w] == 'P')
			mlx_put_image_to_window(game->mlx, game->win,
				game->image.player, w * IMAGE_SIZE, h * IMAGE_SIZE);
		if (game->map_string[h * game->width + w] == 'E'
			&&game->collect_count < game->all_collect)
			mlx_put_image_to_window(game->mlx, game->win,
				game->image.gate_closed, w * IMAGE_SIZE, h * IMAGE_SIZE);
		if (game->map_string[h * game->width + w] == 'E'
			&& game->collect_count == game->all_collect)
			mlx_put_image_to_window(game->mlx, game->win,
				game->image.gate_open, w * IMAGE_SIZE, h * IMAGE_SIZE);
		if (game->map_string[h * game->width + w] == 'C')
			mlx_put_image_to_window(game->mlx, game->win,
				game->image.collectible, w * IMAGE_SIZE, h * IMAGE_SIZE);
	}
}

void	settingimage(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			putimage(game, width, height);
			width++;
		}
		height++;
	}
}
