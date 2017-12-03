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

void convert_map(char *line)
{
	char **tab;
	tab = ft_strsplit(line, ' ');
	
}

void get_map(char *filename)
{
	int fd;
	char *line;

	if (!(fd = open(filename, O_RDONLY)))
		exit(1);
	while (get_next_line(fd, &line))
	{
		convert_map(line);
	}
}
