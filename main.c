/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:03:10 by toroman           #+#    #+#             */
/*   Updated: 2025/01/03 20:29:39 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map copie;
	if (ac != 2)
	{
		ft_printf("ERROR\nits not 2 arguments");
		return 0;
	}
	else 
	{
		t_map	unnom;
		if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 48))
			ft_printf("ERROR\nits not .ber\n");
		checkfiles(av[1], &copie);
		colone(&unnom, av[1]);
		copiemap(&unnom, av[1]);
		checkrectangle(&unnom);
		checkwall(&unnom);
		checkinterior(&unnom);
		checkinterrior2(&unnom);
		checkposition(&unnom);
		flood_fill(&unnom, copie.start_i, copie.start_j);
		copymap(&unnom);
		print_mapcopy(&unnom);
	}
}
