/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:03:23 by toroman           #+#    #+#             */
/*   Updated: 2025/01/07 19:47:03 by tony             ###   ########.fr       */
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
}	t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	**map;
	void	*background;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
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
void	parsing(t_map	*copie);
void	checkflood(t_map *copie);
void	init_map(t_game *game, char **map);
int	close_window(t_game *game);
int	handle_keypress(int codekey, t_game *game);
#endif
