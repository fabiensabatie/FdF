/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:51:42 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/03 14:51:44 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "../includes/libft/libft.h"
#include "../includes/fdf.h"
#include <fcntl.h>

void get_map(char *filename)
{
	int fd;
	char *line;
	int **map = (int**)malloc(sizeof(int*) * 1000);
	char **tab;

	if (!(fd = open(filename, O_RDONLY)))
		exit(1);
	while (get_next_line(fd, &line))
	{
		tab = ft_strsplit(line, ' ');
		*map = (int*)malloc(sizeof(int) * 1000);
		while (*tab)
		{
			**map = ft_atoi(*tab);
			*map= *(map + 1);
			tab++;
		}
		map++;
	}
}
