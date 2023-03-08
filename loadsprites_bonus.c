/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadsprites_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:15:05 by srachdi           #+#    #+#             */
/*   Updated: 2023/01/03 01:15:09 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_map(t_game *game)
{
	int	height;
	int	width;

	game->image.wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &width, &height);
	game->image.ground = mlx_xpm_file_to_image(game->mlx,
			"textures/ground.xpm", &width, &height);
	game->image.gate_closed = mlx_xpm_file_to_image(game->mlx,
			"textures/gateC.xpm", &width, &height);
	game->image.gate_open = mlx_xpm_file_to_image(game->mlx,
			"textures/gateO.xpm", &width, &height);
	game->image.collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/chest.xpm", &width, &height);
	if (!game->image.wall || !game->image.ground || !game->image.gate_closed
		|| !game->image.gate_open || !game->image.collectible)
	{
		write(2, "could'nt load image", 20);
		exitgame(game);
	}
}

void	load_player_right(t_game *game)
{
	int	height;
	int	width;
	int	i;

	game->playermoveright[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/gR0.xpm", &width, &height);
	game->playermoveright[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/gR1.xpm", &width, &height);
	game->playermoveright[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/gR2.xpm", &width, &height);
	game->playermoveright[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/gR3.xpm", &width, &height);
	game->playermoveright[4] = mlx_xpm_file_to_image(game->mlx,
			"textures/gR4.xpm", &width, &height);
	game->playermoveright[5] = mlx_xpm_file_to_image(game->mlx,
			"textures/gR5.xpm", &width, &height);
	i = 0;
	while (i < 5)
	{
		if (!game->playermoveright[++i])
		{
			write(2, "could'nt load image", 20);
			exitgame(game);
		}
	}
}

void	load_player_left(t_game *game)
{
	int	height;
	int	width;
	int	i;

	game->playermoveleft[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/gL0.xpm", &width, &height);
	game->playermoveleft[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/gL1.xpm", &width, &height);
	game->playermoveleft[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/gL2.xpm", &width, &height);
	game->playermoveleft[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/gL3.xpm", &width, &height);
	game->playermoveleft[4] = mlx_xpm_file_to_image(game->mlx,
			"textures/gL4.xpm", &width, &height);
	game->playermoveleft[5] = mlx_xpm_file_to_image(game->mlx,
			"textures/gL5.xpm", &width, &height);
	i = 0;
	while (i < 5)
	{
		if (!game->playermoveleft[++i])
		{
			write(2, "could'nt load image", 20);
			exitgame(game);
		}
	}
}

void	load_player_idle(t_game *game)
{
	int	height;
	int	width;
	int	i;

	game->playeridle[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/gI0.xpm", &width, &height);
	game->playeridle[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/gI1.xpm", &width, &height);
	game->playeridle[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/gI2.xpm", &width, &height);
	game->playeridle[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/gI3.xpm", &width, &height);
	game->playeridle[4] = mlx_xpm_file_to_image(game->mlx,
			"textures/gI4.xpm", &width, &height);
	game->playeridle[5] = mlx_xpm_file_to_image(game->mlx,
			"textures/gI5.xpm", &width, &height);
	i = 0;
	while (i < 5)
	{
		if (!game->playeridle[++i])
		{
			write(2, "could'nt load image", 20);
			exitgame(game);
		}
	}
}

void	load_enemy(t_game *game)
{
	int	height;
	int	width;
	int	i;

	game->enemymove[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/s0.xpm", &width, &height);
	game->enemymove[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/s1.xpm", &width, &height);
	game->enemymove[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/s2.xpm", &width, &height);
	game->enemymove[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/s3.xpm", &width, &height);
	game->enemymove[4] = mlx_xpm_file_to_image(game->mlx,
			"textures/s4.xpm", &width, &height);
	game->enemymove[5] = mlx_xpm_file_to_image(game->mlx,
			"textures/s5.xpm", &width, &height);
	i = 0;
	while (i < 5)
	{
		if (!game->enemymove[++i])
		{
			write(2, "could'nt load image", 20);
			exitgame(game);
		}
	}
}
