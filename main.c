/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:03:10 by toroman           #+#    #+#             */
/*   Updated: 2025/01/08 12:36:26 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map copie;
	t_game game;
	if (ac != 2)
	{
		ft_printf("ERROR\nits not 2 arguments");
		return 0;
	}
	
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 48))
		ft_printf("ERROR\nits not .ber\n");
	checkfiles(av[1], &copie);
	colone(&copie, av[1]);
	copiemap(&copie, av[1]);
	parsing(&copie);
	init_map(&game, copie.map);	
	mlx_hook(game.wind, 17, 0, close_window, &game);
	mlx_loop(game.wind);
}
void parsing(t_map	*copie)
{
		checkrectangle(copie);
		checkwall(copie);
		checkinterior(copie);
		checkinterrior2(copie);
		copymap(copie);
		checkposition(copie);
		copie->map_copy = copymap(copie);
		flood_fill(copie, copie->start_i, copie->start_j);
		print_mapcopy(copie->map_copy);
		checkflood(copie);
}
