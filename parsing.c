/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:51:52 by toroman           #+#    #+#             */
/*   Updated: 2024/12/28 14:37:01 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkfiles(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("ERROR\ncannot open this files");
		exit(EXIT_FAILURE);
	}
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
	{
		ft_printf("ERROR\n files its NULL");
		exit(EXIT_FAILURE);
	}
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
	size_t	countligne;

	countligne = ft_strlen(copie->map[0]);
	i = 1;
	while (copie->map[i])
	{
		if (ft_strlen(copie->map[i]) != countligne)
		{
			ft_printf("this not rectangular");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
