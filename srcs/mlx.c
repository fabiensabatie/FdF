/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:53:57 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/01 18:53:58 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "../includes/fdf.h"

t_mlx_infos	*new_mlx_infos(int win_x, int win_y, char *title)
{
	t_mlx_infos *mlx;

	if (!(mlx = (t_mlx_infos*)malloc(sizeof(t_mlx_infos))))
		return (NULL);
	mlx->init = mlx_init();
	mlx->window = mlx_new_window(mlx->init, win_x, win_y, title);
	return (mlx);
}