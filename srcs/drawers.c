/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:41:47 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/01 18:41:48 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/fdf.h"
#include <mlx.h>
#include <stdio.h>

void 	print_line(t_mlx_infos *mlx, t_dot *start, t_dot *end)
{
	int y;
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
			mlx_pixel_put(mlx->init, mlx->window, x, calc, start->color);
			x++;
		}
	}
	else
	{
		if (start->y > end->y)
		{
			y = end->y;
			while (y < start->y)
			{
				calc = start->x + (y - start->y) * (end->x - start->x) / (end->y - start->y);
				mlx_pixel_put(mlx->init, mlx->window, calc, y, start->color);
				y++;
			}
		}
		else
		{
			y = start->y;
			while (y < end->y)
			{
				calc = start->x + (y - start->y) * (end->x - start->x) / (end->y - start->y);
				mlx_pixel_put(mlx->init, mlx->window, calc, y, start->color);
				y++;
			}
		}
	}
}