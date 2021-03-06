/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 17:05:41 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/29 17:05:44 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fdf.h"
#include <mlx.h>
#include <stdlib.h>

static void		print_line(t_mlx_infos *mlx, t_dot *start, t_dot *end)
{
	int x;
	int y;
	int calc;

	if (start->x > end->x)
		ft_swapdots(start, end);
	if (start->x == end->x && start->y == end->y)
		mlx_pixel_put(mlx->init, mlx->window, start->x, start->y, start->color);
	else if (ft_abs(end->x - start->x) >= ft_abs(end->y - start->y)
	&& (x = start->x))
		while (x <= end->x && (calc = start->y
		+ (x - start->x) * (end->y - start->y) / (end->x - start->x)))
			mlx_pixel_put(mlx->init, mlx->window, x++, calc, end->color);
	else
	{
		if (start->y > end->y && (y = end->y))
			while (y < start->y && (calc = start->x
			+ (y - start->y) * (end->x - start->x) / (end->y - start->y)))
				mlx_pixel_put(mlx->init, mlx->window, calc, y++, end->color);
		else if ((y = start->y))
			while (y < end->y && (calc = start->x
			+ (y - start->y) * (end->x - start->x) / (end->y - start->y)))
				mlx_pixel_put(mlx->init, mlx->window, calc, y++, end->color);
	}
}

static void		print_dots(t_mlx_infos *mlx, t_dot *a, int i, int j)
{
	t_dot *b;
	t_map *map;

	map = mlx->map;
	if (i < map->width - 1)
	{
		b = new_dot(
		((i + 1) * map->tile_width - map->tile_height * j) + map->offx,
		-map->map[j][i + 1] * map->zplus + (map->tile_width / 2 * (i + 1))
		+ (map->tile_height / 2 * j) + map->offy,
		get_color(ft_abs(map->map[j][i + 1])));
		print_line(mlx, a, b);
		free(b);
	}
	if (j < map->height - 1)
	{
		b = new_dot(
		(i * map->tile_width - map->tile_height * (j + 1)) + map->offx,
		-map->map[j + 1][i] * map->zplus + (map->tile_width / 2 * i)
		+ (map->tile_height / 2 * (j + 1)) + map->offy,
		get_color(ft_abs(map->map[j + 1][i])));
		print_line(mlx, a, b);
		free(b);
	}
}

void			draw_map(t_mlx_infos *mlx, t_map *map)
{
	int		i;
	int		j;
	t_dot	*a;

	i = -1;

	mlx->map = map;
	while (i++ < map->width - 1)
	{
		j = 0;
		a = new_dot(
		(i * map->tile_width - map->tile_height * j) + map->offx,
		-map->map[j][i] * map->zplus + (map->tile_width / 2 * i)
		+ (map->tile_height / 2 * j) + map->offy,
		get_color(ft_abs(map->map[j][i])));
		j = -1;
		while (++j < map->height)
			print_dots(mlx, a, i, j);
		free(a);
	}
}
