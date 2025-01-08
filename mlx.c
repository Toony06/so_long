/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:32:38 by toroman           #+#    #+#             */
/*   Updated: 2025/01/08 23:35:15 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_game *game, char **map)
{
	game->height = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		exit(EXIT_FAILURE);
	game->map = map;
	game->width = 0;
	while (map[game->height])
		game->height++;
	game->width = ft_strlen(map[0]);
	game->wind = mlx_new_window(game->mlx, game->width * 64, 
						game->height * 64, "So_long");
}

void	load_image(t_game *game)
{
	int	x;
	int	y;

	game->background = mlx_xpm_file_to_image(game->mlx, "xpm/sol.xpm", &x, &y);
	game->wall = mlx_xpm_file_to_image(game->mlx, "xpm/wall.xpm", &x, &y);
	game->player = mlx_xpm_file_to_image(game->mlx, "xpm/player.xpm", &x, &y);
	game->collectible = mlx_xpm_file_to_image(game->mlx, "xpm/collectible.xpm", &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx, "xpm/exit.xpm", &x, &y);
	if (!game->background || !game->wall || !game->player
			|| !game->collectible || !game->exit)
		{
			ft_error("Error:\nxpm is not avaible", game->copie);
			mlx_destroy_window(game->mlx, game->wind);
			mlx_destroy_display(game->mlx);
			free(game->mlx);
			exit(EXIT_FAILURE);
		}
}

static void	put_image(t_game *game, t_map *map, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->wind, game->background,
			x * 64, y * 64);
	if (map->map[x][y] == '1')
		mlx_put_image_to_window(game->mlx, game->wind, game->wall,
			x * 64, y * 64);
	if (map->map[x][y] == 'C')
		mlx_put_image_to_window(game->mlx, game->wind, game->collectible,
			x * 64, y * 64);
	if (map->map[x][y] == 'P')
		mlx_put_image_to_window(game->mlx, game->wind, game->player,
			x * 64, y * 64);
	if (map->map[x][y] == 'E')
		mlx_put_image_to_window(game->mlx, game->wind, game->exit,
			x * 64, y * 64);
}

void	copie_game(t_game *game, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->height)
	{
		y = 0;
		while(y < game->width)
		{
			put_image(game, map, x, y);
			y++;
		}
		x++;
	}
}
