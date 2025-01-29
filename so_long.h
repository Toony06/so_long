/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:03:23 by toroman           #+#    #+#             */
/*   Updated: 2025/01/29 20:33:07 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "utils/header/libft.h"
# include "utils/header/get_next_line.h"
# include "utils/header/ft_printf.h"
# include <mlx.h>

# define ESC_KEY 65307
# define W_KEY	119
# define A_KEY	97
# define S_KEY	115
# define D_KEY	100

typedef struct s_map
{
	char	**map;
	char	*ligne;
	char	**map_copy;
	int		sizecolone;
	int		i;
	size_t	countligne;
	int		position;
	int		collect;
	int		exit;
	int		j;
	int		start_i;
	int		start_j;
	int		x;
	int		y;
}	t_map;

typedef struct s_game
{
	int		height;
	int		width;
	void	*mlx;
	void	*w;
	char	**map;
	void	*background;
	void	*wall;
	void	*player;
	void	*col;
	void	*exit;
	void	*img;
	t_map	*copie;
	int		x;
	int		y;
	int		count;
	int		player_x;
	int		player_y;
	int		collected;
	int		total_collected;
	int		new_x;
	int		new_y;
}	t_game;

void	checkfiles(char *av, t_map *copie);
void	copiemap(t_map *copie, char *av);
void	colone(t_map *copie, char *av);
void	checkrectangle(t_map *copie);
void	ft_error(char *str, t_map *copie);
void	checkwall(t_map *copie);
void	checkinterior(t_map	*copie);
void	checkinterrior2(t_map *copie);
void	checkposition(t_map *copie);
void	flood_fill(t_map *copie, int i, int j);
void	copymap(t_map *copie);
void	parsing(t_map *copie, t_game *game);
void	checkflood(t_map *copie);
void	init_map(t_game *game, char **map);
int		handle_keypress(int keycode, t_game *game);
void	load_textures(t_game *game);
void	draw_map(t_game *g);
void	moove(t_game *g, int new_x, int new_y);
int		exit_game(t_game *game, int flag);
void	free_map(char **map);
#endif
