/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:41:47 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/17 15:08:14 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/fdf.h"
#include <mlx.h>
#include <stdio.h>

static void		print_rev_line(t_mlx_infos *mlx, t_dot *start, t_dot *end)
{
	int y;
	int calc;

	if (start->y > end->y)
	{
		y = end->y;
		while (y < start->y)
		{
			calc = start->x + (y - start->y) * (end->x - start->x) / (end->y - start->y);
			mlx_pixel_put(mlx->init, mlx->window, calc, y, end->color);
			y++;
		}
	}
	else
	{
		y = start->y;
		while (y < end->y)
		{
			calc = start->x + (y - start->y) * (end->x - start->x) / (end->y - start->y);
			mlx_pixel_put(mlx->init, mlx->window, calc, y, end->color);
			y++;
		}
	}
}

static void		print_line(t_mlx_infos *mlx, t_dot *start, t_dot *end)
{
	int x;
	int calc;

	if (start->x > end->x)
		ft_swapdots(start, end);
	if (start->x == end->x && start->y == end->y)
		mlx_pixel_put(mlx->init, mlx->window, start->x, start->y, start->color);
	else if (ft_abs(end->x - start->x) >= ft_abs(end->y - start->y))
	{
		x = start->x;
		while (x <= end->x)
		{
			calc = start->y + (x - start->x) * (end->y - start->y) / (end->x - start->x);
			mlx_pixel_put(mlx->init, mlx->window, x, calc, end->color);
			x++;
		}
	}
	else
		print_rev_line(mlx, start, end);
}

static void		print_dots(t_mlx_infos *mlx, t_map *map, int i, int j)
{
	t_dot *a;
	t_dot *b;

	a = new_dot(
	(i * map->tile_width - map->tile_height * j) + map->offx,
	-map->map[j][i] * map->zplus + (map->tile_width / 2 * i)
	+ (map->tile_height / 2 * j) + map->offy,
	get_color(ft_abs(map->map[j][i])));
	if (i < map->width - 1)
	{
		b = new_dot(
		((i + 1) * map->tile_width - map->tile_height * j) + map->offx,
		-map->map[j][i + 1] * map->zplus + (map->tile_width / 2 * (i + 1))
		+ (map->tile_height / 2 * j) + map->offy,
		get_color(ft_abs(map->map[j][i + 1])));
		print_line(mlx, a, b);
	}
	if (j < map->height - 1)
	{
		b = new_dot(
		(i * map->tile_width - map->tile_height * (j + 1)) + map->offx,
		-map->map[j + 1][i] * map->zplus + (map->tile_width / 2 * i)
		+ (map->tile_height / 2 * (j + 1)) + map->offy,
		get_color(ft_abs(map->map[j + 1][i])));
		print_line(mlx, a, b);
	}
}

void			draw_map(t_mlx_infos *mlx, t_map *map)
{
	int i;
	int j;

	mlx_string_put(mlx->init, mlx->window, 10, 10, 0x00FFFFFF,
	ft_strjoin("OFFX = ", ft_itoa(map->offx)));
	mlx_string_put(mlx->init, mlx->window, 10, 25, 0x00FFFFFF,
	ft_strjoin("OFFY = ", ft_itoa(map->offy)));
	mlx_string_put(mlx->init, mlx->window, 10, 40, 0x00FFFFFF,
	ft_strjoin("ZPLUS = ", ft_itoa(map->zplus)));
	mlx_string_put(mlx->init, mlx->window, 10, 55, 0x00FFFFFF,
	ft_strjoin("WIDTH = ", ft_itoa(map->tile_width)));
	mlx_string_put(mlx->init, mlx->window, 10, 70, 0x00FFFFFF,
	ft_strjoin("HEIGHT = ", ft_itoa(map->tile_height)));

	i = -1;
	while (i++ < map->width - 1)
	{
		j = -1;
		while (++j < map->height)
			print_dots(mlx, map, i, j);
	}
}
