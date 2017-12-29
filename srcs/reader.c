/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:51:42 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/25 13:29:28 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../includes/fdf.h"
#include <fcntl.h>
#include <stdio.h>

static int	**init_map(char *filename, t_map *input)
{
	int fd;
	int spaces;
	char *line;
	int **map;
	char **tab;

	spaces = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
		ft_putnexit("Please make sure that the file exists.");
	while (get_next_line(fd, &line) && (input->height += 1))
	{
		input->width = 0;
		tab = ft_strsplit(line, ' ');
		while (tab[input->width])
		{
			free (tab[input->width]);
			input->width++;
		}
		free (tab);
		free (line);
	}
	close(fd);
	fd = input->height;
	if (!(map = (int**)malloc(sizeof(int*) * (fd + 1))))
		exit(1);
	map[fd] = NULL;
	while (--fd >= 0)
		if (!(map[fd] = (int*)malloc(sizeof(int) * (input->width + 1))))
			exit(1);
	return (map);
}

static void	convert_map(int fd, t_map *map)
{
	int i;
	int j;
	char **tab;
	char *line;

	j = 0;
	i = 0;
	while (get_next_line(fd, &line))
	{
		j = 0;
		tab = ft_strsplit(line, ' ');
		while (tab[j])
		{
			map->map[i][j] = ft_atoi(tab[j]);
			free (tab[j++]);
		}
		free (line);
		free (tab);
		if (j != map->width)
			ft_putnexit("Invalid map");
		i++;
	}
	if (i != map->height)
		ft_putnexit("Invalid map");
}

t_map	*get_map(char *filename)
{
	t_map *map;
	int fd;

	fd = 0;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		exit(1);
	map->map = init_map(filename, map);
	if (!(fd = open(filename, O_RDONLY)))
		exit(1);
	convert_map(fd, map);
	close(fd);
	map->tile_width = 10;
	map->tile_height = 10;
	map->offx = WINX / 2;
	map->offy = WINY / 2;
	map->zplus = 2;
	return (map);
}

