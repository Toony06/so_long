/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:07:00 by tony              #+#    #+#             */
/*   Updated: 2025/01/29 12:02:27 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkposition(t_map *copie)
{
	int	i;
	int	j;

	copie->start_i = 0;
	copie->start_j = 0;
	i = 0;
	while (copie->map[i])
	{
		j = 0;
		while (copie->map[i][j])
		{
			if (copie->map[i][j] == 'P')
			{
				copie->start_i = i;
				copie->start_j = j;
			}
			j++;
		}
		i++;
	}
	if (copie->start_i == 0 || copie->start_j == 0)
		ft_error("Error:\nnot position declared in the map", copie);
}

void	flood_fill(t_map *copie, int i, int j)
{
	if (i < 0 || j < 0 || i >= copie->sizecolone
		|| j >= (int)ft_strlen(copie->map_copy[i])
		|| copie->map_copy[i][j] == '1' || copie->map_copy[i][j] == 'V'
		|| copie->map_copy[i][j] == 'E')
		return ;
	copie->map_copy[i][j] = 'V';
	flood_fill(copie, i + 1, j);
	flood_fill(copie, i - 1, j);
	flood_fill(copie, i, j + 1);
	flood_fill(copie, i, j - 1);
}

void copymap(t_map *copie)
{
	int		i;

	i = 0;
	copie->map_copy = malloc(sizeof(char *) * (copie->sizecolone + 1));
	if (!copie->map_copy)
		ft_error("Error\n", copie);
	while (i < copie->sizecolone)
	{
		copie->map_copy[i] = ft_strdup(copie->map[i]);
		i++;
	}
	copie->map_copy[i] = NULL;
}

void	checkflood(t_map *copie)
{
	int	i;
	int	j;

	i = 0;
	while (copie->map_copy[i])
	{
		j = 0;
		while (copie->map_copy[i][j])
		{
			if (copie->map_copy[i][j] == 'C')
				ft_error("Error:\nnot reach all collectible", copie);
			if (copie->map_copy[i][j] == 'E')
			{
				if (copie->map_copy[i + 1][j] != 'V' &&
					copie->map_copy[i - 1][j] != 'V' &&
					copie->map_copy[i][j + 1] != 'V' &&
					copie->map_copy[i][j - 1] != 'V')
					ft_error("Error:\nexit are not valid", copie);
			}
			j++;
		}
		i++;
	}
}
