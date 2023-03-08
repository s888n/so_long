/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:22:36 by srachdi           #+#    #+#             */
/*   Updated: 2023/01/01 16:40:08 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moves(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(game->map_string))
	{
		if (game->map_string[i] == 'P')
			break ;
	}
	if (game->map_string[i + game->width] == 'C')
		game->collect_count++;
	if (game->map_string[i + game->width] == 'E'
		&& game->all_collect == game->collect_count)
		exitgame(game);
	else if (game->map_string[i + game->width] != '1'
		&& game->map_string[i + game->width] != 'E')
	{
		game->map_string[i] = '0';
		game->map_string[i + game->width] = 'P';
		game->walk_count++;
		ft_putchar('\n');
		ft_putnbr(game->walk_count);
		settingimage(game);
	}
}

void	movew(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(game->map_string))
	{
		if (game->map_string[i] == 'P')
			break ;
	}
	if (game->map_string[i - game->width] == 'C')
		game->collect_count++;
	if (game->map_string[i - game->width] == 'E'
		&& game->all_collect == game->collect_count)
		exitgame(game);
	else if (game->map_string[i - game->width] != '1'
		&& game->map_string[i - game->width] != 'E')
	{
		game->map_string[i] = '0';
		game->map_string[i - game->width] = 'P';
		game->walk_count++;
		ft_putchar('\n');
		ft_putnbr(game->walk_count);
		settingimage(game);
	}
}

void	movea(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(game->map_string))
	{
		if (game->map_string[i] == 'P')
			break ;
	}
	if (game->map_string[i - 1] == 'C')
		game->collect_count++;
	if (game->map_string[i - 1] == 'E'
		&& game->all_collect == game->collect_count)
		exitgame(game);
	else if (game->map_string[i - 1] != '1'
		&& game->map_string[i - 1] != 'E')
	{
		game->map_string[i] = '0';
		game->map_string[i - 1] = 'P';
		game->walk_count++;
		ft_putchar('\n');
		ft_putnbr(game->walk_count);
		game->image.player = game->image.player_left;
		settingimage(game);
	}
}

void	moved(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(game->map_string))
	{
		if (game->map_string[i] == 'P')
			break ;
	}
	if (game->map_string[i + 1] == 'C')
		game->collect_count++;
	if (game->map_string[i + 1] == 'E'
		&& game->all_collect == game->collect_count)
		exitgame(game);
	else if (game->map_string[i + 1] != '1'
		&& game->map_string[i + 1] != 'E')
	{
		game->map_string[i] = '0';
		game->map_string[i + 1] = 'P';
		game->walk_count++;
		ft_putchar('\n');
		ft_putnbr(game->walk_count);
		settingimage(game);
	}
}

int	keypress(int key_code, t_game *game)
{
	if (key_code == KEY_S)
		moves(game);
	if (key_code == KEY_A)
	{
		game->image.player = game->image.player_left;
		movea(game);
	}
	if (key_code == KEY_W)
		movew(game);
	if (key_code == KEY_D)
	{
		game->image.player = game->image.player_right;
		moved(game);
	}
	if (key_code == KEY_ESC)
		exitgame(game);
	return (0);
}
