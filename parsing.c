/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:51:52 by toroman           #+#    #+#             */
/*   Updated: 2025/01/29 11:56:31 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkfiles(char *av, t_map *copie)
{
	int	fd;

	fd = open(av, __O_DIRECTORY);
	if (fd != -1)
	{
		ft_error("Error:\nits not file", copie);
		exit(EXIT_FAILURE);
	}
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_error("ERROR:\ncannot open this file", copie);
	close (fd);
}

void	copiemap(t_map *copie, char *av)
{
	int		fd;
	int		i;
	char	*ligne;

	i = 0;
	fd = open(av, O_RDONLY);
	copie->map = malloc(sizeof(char *) * (copie->sizecolone + 1));
	if (!copie->map)
		ft_error("Error", copie);
	ligne = get_next_line(fd);
	while (ligne)
	{
		copie->map[i++] = ft_strdup(ligne);
		free(ligne);
		ligne = get_next_line(fd);
	}
	copie->map[i] = NULL;
}

void	colone(t_map *copie, char *av)
{
	int		fd;
	char	*count;

	fd = open(av, O_RDONLY);
	count = get_next_line(fd);
	if (!count)
		ft_error("Error:\nthis file is null", copie);
	copie->sizecolone = 0;
	while (count)
	{
		free(count);
		copie->sizecolone++;
		count = get_next_line(fd);
	}
	close(fd);
}

void	checkrectangle(t_map *copie)
{
	int	i;

	copie->countligne = ft_strlen(copie->map[0]);
	i = 1;
	while (copie->map[i])
	{
		if (ft_strlen(copie->map[i]) != copie->countligne)
			ft_error("Error:\nthis map its not valid", copie);
		i++;
	}
}

void	ft_error(char *str, t_map *copie)
{
	ft_printf(str);
	if (copie->map != NULL)
		free_map(copie->map);
	else if (copie->map_copy != NULL)
		free_map(copie->map_copy);
	exit(EXIT_FAILURE);
}
