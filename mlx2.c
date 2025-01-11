/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:37:43 by tony              #+#    #+#             */
/*   Updated: 2025/01/11 17:10:43 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moove(t_game *g, t_map *m, int new_x, int new_y)
{
	ft_printf("moove player\n%d", g->count);
	if (m->map[new_y][new_x] == '1')
		return ;
	if (m->map[new_y][new_x] == 'C')
	{
		m->map[new_y][new_x] = '0';
		g->collected++;
	}
	if (m->map[new_y][new_x] == 'E')
	{
		if (g->collected == g->total_collected)
			close_window(g);
		return ;
	}
	m->map[g->player_y][g->player_x] = '0';
	m->map[new_y][new_x] = 'P';
	g->player_y = new_y;
	g->player_x = new_x;
	draw_map(g, m);
}
