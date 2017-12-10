/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:51:42 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/10 15:51:51 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>
#include "../includes/libft/libft.h"
#include "../includes/fdf.h"
#include <fcntl.h>

int	**init_map(char *filename, t_map *input)
{
	int fd;
	int ret;
	char *line;
	char **tab;
	int **map;

	ret = 0;
	if (!(fd = open(filename, O_RDONLY)))
		exit(1);
	while (get_next_line(fd, &line))
		ret++;
	tab = ft_strsplit(line, ' ');
	close(fd);
	fd = 0;
	while (*tab++)
		fd++;
	input->height = ret;
	input->width = fd;
	if (!(map = (int**)malloc(sizeof(int*) * (ret + 1))))
		exit(1);
	map[ret] = NULL;
	while (--ret >= 0)
		if (!(map[ret] = (int*)malloc(sizeof(int) * (fd + 1))))
			exit(1);
	return (map);
}

void	read_map(t_map *map)
{
	int i;
	int j;

	i = -1;
	while (i++ < map->height - 1)
	{
		j = -1;
		while (++j < map->width)
			ft_putnbr(map->map[i][j]);
		ft_putendl("");
	}
}

void	convert_map(int fd, t_map *map)
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
			j++;
		}
		i++;
	}
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
	map->tile_width = 2;
	map->tile_height = 2;
	map->offx = WINX / 2;
	map->offy = 0;
	map->zplus = 2;
	return (map);
}

