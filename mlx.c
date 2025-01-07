/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:32:38 by toroman           #+#    #+#             */
/*   Updated: 2025/01/07 19:46:31 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_game *game, char **map)
{
	int	height;
	int	width;

	game->mlx_ptr = mlx_init();
	if(!game->mlx_ptr)
		exit(EXIT_FAILURE);
	game->map = map;
	height = 0;
	while(map[height])
		height++;
	width = ft_strlen(map[0]);
	game->mlx_win = mlx_new_window(game->mlx_ptr, width * 64, height * 64, "so_long");
	mlx_hook(game->mlx_win, 17, 0, close_window, game);
	mlx_key_hook(game->mlx_win, handle_keypress, game);
}

int	close_window(t_game *game)
{
	if (game->mlx_win)
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	exit(EXIT_FAILURE);
	return (0);
}

int	handle_keypress(int codekey, t_game *game)
{
	if (codekey == ESC_KEY)
		close_window(game);
	return (0);
}

// void	to_load_image(t_game *game)
// {
	
// }
