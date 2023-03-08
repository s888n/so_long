/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:14:06 by srachdi           #+#    #+#             */
/*   Updated: 2023/01/03 01:14:11 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	if ((game->map_string[i + game->width] != '1'
			&& game->map_string[i + game->width] != 'E')
		|| game->map_string[i + game->width] == 'x')
	{
		game->map_string[i] = '0';
		game->map_string[i + game->width] = 'P';
		game->walk_count++;
		settingimage(game, game->playermoveleft);
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
	if ((game->map_string[i - game->width] == 'E'
			&& game->all_collect == game->collect_count)
		||game->map_string[i - game->width] == 'x')
		exitgame(game);
	else if (game->map_string[i - game->width] != '1'
		&& game->map_string[i - game->width] != 'E')
	{
		game->map_string[i] = '0';
		game->map_string[i - game->width] = 'P';
		game->walk_count++;
		settingimage(game, game->playermoveright);
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
	if ((game->map_string[i - 1] == 'E'
			&& game->all_collect == game->collect_count)
		|| game->map_string[i - 1] == 'x')
		exitgame(game);
	else if (game->map_string[i - 1] != '1'
		&& game->map_string[i - 1] != 'E')
	{
		game->map_string[i] = '0';
		game->map_string[i - 1] = 'P';
		game->walk_count++;
		settingimage(game, game->playermoveleft);
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
	if ((game->map_string[i + 1] == 'E'
			&& game->all_collect == game->collect_count)
		||game->map_string[i +1] == 'x')
		exitgame(game);
	else if (game->map_string[i + 1] != '1'
		&& game->map_string[i + 1] != 'E')
	{
		game->map_string[i] = '0';
		game->map_string[i + 1] = 'P';
		game->walk_count++;
		settingimage(game, game->playermoveright);
	}
}

int	keypress(int key_code, t_game *game)
{	
	if (key_code == KEY_S)
	{
		moves(game);
		game->moving = 1;
	}
	if (key_code == KEY_A)
	{
		game->moving = 1;
		game->direction = -1;
		movea(game);
	}
	if (key_code == KEY_W)
	{
		game->moving = 1;
		movew(game);
	}
	if (key_code == KEY_D)
	{
		game->moving = 1;
		game->direction = 1;
		moved(game);
	}
	if (key_code == KEY_ESC)
		exitgame(game);
	return (0);
}
