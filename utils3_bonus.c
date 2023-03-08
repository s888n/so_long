/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:13:33 by srachdi           #+#    #+#             */
/*   Updated: 2023/01/03 01:13:38 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	updateenemy(t_game *game)
{
	static int	direction;
	int			i;

	if (!direction)
		direction = 1;
	i = 0;
	while (i++ < (int)ft_strlen(game->map_string))
		if (game->map_string[i] == 'x')
			break ;
	if (game->map_string[i + direction] == '1')
	{
		game->image.enemy = game->enemymove[0];
		direction *= -1;
	}
	else if (game->map_string[i + direction] == '0')
	{
		game->map_string[i] = '0';
		game->map_string[i + direction] = 'x';
	}
	else if (game->map_string[i + direction] == 'P')
		exitgame(game);
}

int	release(int key, t_game *game)
{
	if (key == KEY_A || key == KEY_D || key == KEY_S || key == KEY_W)
		game->moving = 0;
	return (0);
}

int	refresh(t_game *game)
{
	char	*walk_counter;

	if (game->moving == 0)
		settingimage(game, game->playeridle);
	if (game->moving == 1 && game->direction == 1)
		settingimage(game, game->playermoveright);
	if (game->moving == 1 && game->direction == -1)
		settingimage(game, game->playermoveleft);
	usleep(85000);
	updateenemy(game);
	walk_counter = int_to_string(game->walk_count);
	mlx_string_put(game->mlx, game->win, game->width * IMAGE_SIZE / 2,
		IMAGE_SIZE / 2, 0xFF0000, walk_counter);
	free(walk_counter);
	mlx_do_sync(game->mlx);
	return (0);
}

int	int_len(int number)
{
	int	count;

	count = 0;
	while (number != 0)
	{
		count++;
		number /= 10;
	}
	return (count);
}

void	reverse_string(char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
}
