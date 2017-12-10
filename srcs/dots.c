/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:04:17 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/08 14:01:33 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <mlx.h>
#include <stdlib.h>

t_dot	*new_dot(int x, int y, int color)
{
	t_dot *dot;

	if (!(dot = (t_dot*)malloc(sizeof(t_dot))))
		return (NULL);
	dot->x = x;
	dot->y = y;
	dot->color = color;
	return (dot);
}

int		get_color(int z)
{
	int color = 0x00FFFFFF;
	while (z--)
		color -= 239000;
	return (color);
}

void	ft_swapdots(t_dot *a, t_dot *b)
{
	t_dot tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_swapdotcoor(t_dot *dot)
{
	int tmp;

	tmp = dot->x;
	dot->x = dot->y;
	dot->y = tmp;
}