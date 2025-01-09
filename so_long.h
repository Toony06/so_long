/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:03:23 by toroman           #+#    #+#             */
/*   Updated: 2025/01/09 22:40:39 by tony             ###   ########.fr       */
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
	void	*wind;
	char	**map;
	void	*background;
	void	*wall;
	void	*player;
	void	*collectible;
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
char	**copymap(t_map *copie);
void	print_mapcopy(char **map);
void	parsing(t_map *copie, t_game *game);
void	checkflood(t_map *copie);
void	init_map(t_game *game, char **map);
int		close_window(t_game *game);
int		handle_keypress(int keycode, t_game *game);
void	load_textures(t_game *game);
void	draw_map(t_game *g, t_map *map);
#endif
