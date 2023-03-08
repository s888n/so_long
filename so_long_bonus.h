/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srachdi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:14:33 by srachdi           #+#    #+#             */
/*   Updated: 2023/01/03 01:14:43 by srachdi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define IMAGE_SIZE 64
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2
# define KEY_A 0
# define KEY_ESC 53
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# define MAX_HEIGHT 1000
# define MAX_WIDTH 1000

typedef struct s_image
{
	void	*wall;
	void	*ground;
	void	*player;
	void	*enemy;
	void	*gate_closed;
	void	*gate_open;
	void	*collectible;
}	t_image;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	*map_string;
	int		collect_count;
	int		all_collect;
	int		player_count;
	int		exit_count;
	int		walk_count;
	int		moving;
	int		direction;
	void	*playermoveright[6];
	void	*playermoveleft[6];
	void	*playeridle[6];
	void	*enemymove[6];
	t_image	image;
}	t_game;

typedef struct s_maze
{
	int		height;
	int		width;
	char	m[MAX_HEIGHT][MAX_WIDTH];
	int		visited[MAX_HEIGHT][MAX_WIDTH];
}	t_maze;

int		main(int ac, char *av[]);
int		ft_strchr(char *str, int c);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *storage, char *readstr);
size_t	ft_strlen_n(char *s);
char	*ft_strjoin_n(char *s1, char *s2);
int		int_len(int number);
char	*int_to_string(int number);
void	reverse_string(char *str);
int		release(int key, t_game *game);
int		isber(char *filename);
void	checkfile(int ac, char *av);
char	*get_next_line(int fd);
char	*readandstore(int fd, char *storage);
char	*resetstorage(char *storage);
char	*extractline(char *storage);
char	*readmap(char *filename, t_game *game);
int		checkstrangechar(char *str1, char *str2);
int		checkmapstring(t_game *game);
int		checkwalls(t_game *game);
int		isvalid(t_maze *maze, int i, int j);
int		search(t_maze *maze, int i, int j);
void	init_maze(t_maze *maze, t_game *game);
int		validpath(t_game *game);
void	checkmap(t_game *game);
void	image_to_window(t_game *game, int w, int h, void *image);
void	loadimages(t_game *game);
void	load_map(t_game *game);
void	load_player_right(t_game *game);
void	load_player_left(t_game *game);
void	load_player_idle(t_game *game);
void	load_enemy(t_game *game);
void	putimage(t_game *game, int w, int h, void *arr[]);
void	settingimage(t_game *game, void *arr[]);
void	moves(t_game *game);
void	movew(t_game *game);
void	movea(t_game *game);
void	moved(t_game *game);
int		keypress(int key_code, t_game *game);
void	updateenemy(t_game *game);
int		refresh(t_game *game);
int		exiterror(char *message);
int		exitgame(t_game *game);
void	exitmap(t_game *game, char *message);
#endif
