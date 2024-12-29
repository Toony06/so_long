/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:51:52 by toroman           #+#    #+#             */
/*   Updated: 2024/12/29 23:29:52 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkfiles(char *av, t_map *copie)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_error("ERROR:\ncannot open this file", copie);
	close (fd);
}

void copiemap(t_map *copie, char *av)
{
	int	fd;
	int	i;
	char *ligne;

	i = 0;
	fd = open(av, O_RDONLY);
	copie->map = malloc(sizeof(char *) * (copie->sizecolone + 1));
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
	int	fd;
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
	int	i;

	i = 0;
	ft_printf(str);
	while(copie->map[i])
	{
		free(copie->map[i]);
		i++;
	}
	free (copie->map);
	exit(EXIT_FAILURE);
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
	while (copie->map[copie->sizecolone - 1][copie->i] && copie->map[copie->sizecolone - 1][copie->i] != '\n')
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
	while(copie->i < copie->sizecolone)
	{
		if (copie->map[copie->i++][copie->countligne - 2] != '1')
			ft_error("Error:\nthe last column or not avaible", copie);
	}
}
