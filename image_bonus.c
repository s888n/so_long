/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:12:18 by srachdi           #+#    #+#             */
/*   Updated: 2023/01/03 01:12:22 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	loadimages(t_game *game)
{
	load_map(game);
	load_player_right(game);
	load_player_left(game);
	load_player_idle(game);
	load_enemy(game);
}

void	image_to_window(t_game *game, int w, int h, void *image)
{
	mlx_put_image_to_window(game->mlx, game->win,
		image, w * IMAGE_SIZE, h * IMAGE_SIZE);
}

void	putimage(t_game *game, int w, int h, void *arr[])
{
	static int	frame;

	frame = (frame + 1) % 6;
	game->image.player = arr[frame];
	if (game->map_string[h * game->width + w] == '1')
		image_to_window(game, w, h, game->image.wall);
	else
	{
		image_to_window(game, w, h, game->image.ground);
		if (game->map_string[h * game->width + w] == 'P')
			image_to_window(game, w, h, game->image.player);
		if (game->map_string[h * game->width + w] == 'E'
			&& game->all_collect > game->collect_count)
			image_to_window(game, w, h, game->image.gate_closed);
		if (game->map_string[h * game->width + w] == 'E'
			&& game->all_collect == game->collect_count)
			image_to_window(game, w, h, game->image.gate_open);
		if (game->map_string[h * game->width + w] == 'C')
			image_to_window(game, w, h, game->image.collectible);
		if (game->map_string[h * game->width + w] == 'x')
			image_to_window(game, w, h, game->enemymove[frame]);
	}
}

void	settingimage(t_game *game, void *arr[])
{
	int	height;
	int	width;

	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			putimage(game, width, height, arr);
			width++;
		}
		height++;
	}
}
