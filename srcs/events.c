/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 10:28:01 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/08 14:31:12 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

static void	move(int keycode, t_mlx_infos *mlx)
{
	if (keycode == 126)
		mlx->map->offy -= 10;
	if (keycode == 125)
		mlx->map->offy += 10;
	if (keycode == 123)
		mlx->map->offx -= 10;
	if (keycode == 124)
		mlx->map->offx += 10;
	mlx_clear_window(mlx->init, mlx->window);
	draw_map(mlx, mlx->map);
}

static void	zoom(int keycode, t_mlx_infos *mlx)
{
	if (keycode == 35)
	{
		mlx->map->tile_width += 1;
		mlx->map->tile_height += 1;
	}
	if (keycode == 41)
	{
		if (mlx->map->tile_width > 0)
		{
			mlx->map->tile_width -= 1;
			mlx->map->tile_height -= 1;
		}
	}
	mlx_clear_window(mlx->init, mlx->window);
	draw_map(mlx, mlx->map);
}

static void	changez(int keycode, t_mlx_infos *mlx)
{
	if (keycode == 12)
		mlx->map->zplus -= 1;
	if (keycode == 13)
		mlx->map->zplus += 1;
	mlx_clear_window(mlx->init, mlx->window);
	draw_map(mlx, mlx->map);
}

int			handle_events(int keycode, t_mlx_infos *mlx)
{
	if (keycode == 53)
		exit(1);
	if (keycode >= 123 && keycode <= 126)
		move(keycode, mlx);
	if (keycode == 35 || keycode == 41)
		zoom(keycode, mlx);
	if (keycode == 12 || keycode == 13)
		changez(keycode, mlx);
	return (0);
}