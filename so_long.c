/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:12:02 by srachdi           #+#    #+#             */
/*   Updated: 2023/01/03 01:12:05 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exiterror(char *message)
{
	write (2, "error\n", 6);
	write (2, message, ft_strlen(message));
	exit (EXIT_FAILURE);
}

int	exitgame(t_game *game)
{
	mlx_destroy_window (game->mlx, game->win);
	free (game->map_string);
	free (game);
	exit (EXIT_SUCCESS);
}

void	initgame(t_game *game, char *map)
{
	game->collect_count = 0;
	game->walk_count = 0;
	game->player_count = 0;
	game->all_collect = 0;
	game->exit_count = 0;
	game->map_string = readmap (map, game);
	checkmap (game);
	game->mlx = mlx_init();
	if (!game->mlx)
		exitmap (game, "mlx failed :(");
	game->win = mlx_new_window (game->mlx, game->width * IMAGE_SIZE,
			game->height * IMAGE_SIZE, "./so_long");
	if (!game->win)
		exitmap(game, "couldn't open window :(");
	loadimages (game);
	ft_putnbr (game->walk_count);
	game->image.player = game->image.player_right;
}

int	main(int ac, char *av[])
{
	t_game	*game;

	checkfile (ac, av[1]);
	game = malloc (sizeof (t_game));
	initgame (game, av[1]);
	settingimage (game);
	mlx_hook (game->win, 2, 0, keypress, game);
	mlx_hook (game->win, 17, 0, exitgame, game);
	mlx_loop (game->mlx);
	free (game);
}
