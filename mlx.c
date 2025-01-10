/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:32:38 by toroman           #+#    #+#             */
/*   Updated: 2025/01/10 14:27:39 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_game *game, char **map)
{
	int	height;
	int	width;

	game->mlx = mlx_init();
	if (!game->mlx)
		exit(EXIT_FAILURE);
	game->map = map;
	if (!game->map)
		exit(EXIT_FAILURE);
	height = 0;
	while (map[height])
		height++;
	width = ft_strlen(map[0]) - 1;
	game->height = height;
	game->width = width;
	game->w = mlx_new_window(game->mlx, width * 64, height * 64, "So_long");
	mlx_hook(game->w, 17, 0, close_window, game);
	mlx_key_hook(game->w, handle_keypress, game);
}

int	close_window(t_game *game)
{
	if (game->w)
		mlx_destroy_window(game->mlx, game->w);
	exit(EXIT_FAILURE);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		close_window(game);
	return (0);
}

void	load_textures(t_game *game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	game->background = mlx_xpm_file_to_image(game->mlx,
			"xpm/sol.xpm", &width, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"xpm/wall.xpm", &width, &height);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"xpm/player.xpm", &width, &height);
	game->col = mlx_xpm_file_to_image(game->mlx,
			"xpm/collectible.xpm", &width, &height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "xpm/exit.xpm",
			&width, &height);
	if (!game->background || !game->wall || !game->player || !game->col
		|| !game->exit)
	{
		ft_printf("Error:\nxpm file is not avaible\n");
		mlx_destroy_window(game->mlx, game->w);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(EXIT_FAILURE);
	}
}

void	draw_map(t_game *g, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			mlx_put_image_to_window(g->mlx, g->w, g->background,
				x * 64, y * 64);
			if (map->map[y][x] == '1')
				mlx_put_image_to_window(g->mlx, g->w, g->wall, x * 64, y * 64);
			if (map->map[y][x] == 'P')
				mlx_put_image_to_window(g->mlx, g->w, g->player, x * 64,
					y * 64);
			if (map->map[y][x] == 'E')
				mlx_put_image_to_window(g->mlx, g->w, g->exit, x * 64, y * 64);
			if (map->map[y][x] == 'C')
				mlx_put_image_to_window(g->mlx, g->w, g->col, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
