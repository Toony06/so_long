/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:37:43 by tony              #+#    #+#             */
/*   Updated: 2025/01/29 12:11:24 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moove(t_game *g, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= g->width || new_y < 0 || new_y >g->height)
		return ;
	if (g->map[new_y][new_x] == '1')
		return ;
	ft_printf("moove player : %d\n", g->count);
	if (g->map[new_y][new_x] == 'C')
	{
		g->map[new_y][new_x] = '0';
		g->collected++;
	}
	if (g->map[new_y][new_x] == 'E')
	{
		if (g->collected == g->total_collected)
		{
			ft_printf("FELICITATION");
			exit_game(g, 0);
			return ;
		}
	}
	g->map[g->player_y][g->player_x] = '0';
	g->map[new_y][new_x] = 'P';
	g->player_y = new_y;
	g->player_x = new_x;
	g->count++;
	draw_map(g);
}

int	exit_game(t_game *game, int flag)
{
	if (game->copie != NULL)
		free_map(game->copie->map);
	if (game->background)
		mlx_destroy_image(game->mlx, game->background);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->col)
		mlx_destroy_image(game->mlx, game->col);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_window(game->mlx, game->w);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map);
	exit(flag);
}

void	init_game_xpm(t_game *game)
{
	game->background = NULL;
	game->wall = NULL;
	game->player = NULL;
	game->col = NULL;
	game->exit = NULL;
}
