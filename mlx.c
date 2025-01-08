/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:32:38 by toroman           #+#    #+#             */
/*   Updated: 2025/01/08 12:33:51 by toroman          ###   ########.fr       */
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
	mlx_hook(game->wind, 17, 0, close_window, game);
	mlx_loop(game->wind);
}

int	close_window(t_game *game)
{
	if (game->mlx)
		mlx_destroy_window(game->mlx, game->wind);
	exit(EXIT_SUCCESS);
	return (0);
}
// void	to_load_image(t_game *game)
// {
// }
