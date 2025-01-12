/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:37:43 by tony              #+#    #+#             */
/*   Updated: 2025/01/12 23:07:02 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moove(t_game *g, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= g->width || new_y < 0 || new_y >g->height)
		return ;
	ft_printf("moove player : %d", g->count);
	printf("Tentative de déplacement vers [%d][%d]\n", new_x, new_y);
	if (g->map[new_y][new_x] == '1')
		return ;
	if (g->map[new_y][new_x] == 'C')
	{
		g->map[new_y][new_x] = '0';
		g->collected++;
	}
	if (g->map[new_y][new_x] == 'E')
	{
		if (g->collected == g->total_collected)
		{
			close_window(g);
		return ;
	}
	g->map[g->player_y][g->player_x] = '0';
	g->map[new_y][new_x] = 'P';
	g->player_y = new_y;
	g->player_x = new_x;
	draw_map(g);
}
