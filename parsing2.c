/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 22:53:10 by tony              #+#    #+#             */
/*   Updated: 2025/01/15 19:27:00 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
void	checkwall(t_map *copie)
{
	copie->i = 0;
	while (copie->map[0][copie->i] && copie->map[0][copie->i] != '\n')
	{
		if (copie->map[0][copie->i++] != '1')
			ft_error("Error:\nthe first line or not available", copie);
	}
	copie->i = 0;
	while (copie->map[copie->sizecolone - 1][copie->i]
			&& copie->map[copie->sizecolone - 1][copie->i] != '\n')
	{
		if (copie->map[copie->sizecolone - 1][copie->i++] != '1')
			ft_error("Error:\nthe last line or not avaible", copie);
	}
	copie->i = 0;
	while (copie->i < copie->sizecolone)
	{
		if (copie->map[copie->i++][0] != '1')
			ft_error("Error:\nthe first column or not avaible", copie);
	}
	copie->i = 0;
	while (copie->i < copie->sizecolone)
	{
		if (copie->map[copie->i++][copie->countligne - 2] != '1')
			ft_error("Error:\nthe last column or not avaible", copie);
	}
}

void	checkinterior(t_map *copie)
{
	copie->i = 0;
	copie->exit = 0;
	copie->position = 0;
	copie->collect = 0;
	while (copie->map[copie->i])
	{
		copie->j = 0;
		while (copie->map[copie->i][copie->j])
		{
			if (copie->map[copie->i][copie->j] == 'E')
				copie->exit++;
			if (copie->map[copie->i][copie->j] == 'P')
				copie->position++;
			if (copie->map[copie->i][copie->j] == 'C')
				copie->collect++;
			else if (copie->exit > 1 || copie->position > 1)
				ft_error("Error:\nthis map has more E or P", copie);
			copie->j++;
		}
		copie->i++;
	}
	if (copie->exit == 0 || copie->position == 0 || copie->collect < 1)
		ft_error("Error:\ninterrior or not avaible", copie);
}

void	checkinterrior2(t_map *copie)
{
	int	i;
	int	j;

	i = 0;
	while (copie->map[i])
	{
		j = 0;
		while (copie->map[i][j])
		{
			if (copie->map[i][j] != '1' && copie->map[i][j] != '0' &&
				copie->map[i][j] != 'E' && copie->map[i][j] != 'C' &&
				copie->map[i][j] != 'P' && copie->map[i][j] != '\n')
				ft_error("Error:\this map are other char", copie);
			j++;
		}
		i++;
	}
}
