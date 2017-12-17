/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:24:37 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/17 14:59:08 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/libft/libft.h"
#include "../includes/fdf.h"
#include <stdlib.h>

static t_mlx_infos	*new_mlx_infos(int win_x, int win_y, char *title)
{
	t_mlx_infos *mlx;

	if (!(mlx = (t_mlx_infos*)malloc(sizeof(t_mlx_infos))))
		return (NULL);
	mlx->init = mlx_init();
	mlx->window = mlx_new_window(mlx->init, win_x, win_y, title);
	return (mlx);
}

int main(int argc, char **argv)
{
	t_mlx_infos *mlx;

	if (argc != 2)
		ft_putnexit("usage : ./fdf [map]");
	mlx = new_mlx_infos(WINX, WINY, ft_strjoin("FDF - ", argv[1]));
	mlx->map = get_map(argv[1]);
	draw_map(mlx, mlx->map);
	mlx_key_hook(mlx->window, handle_events, mlx);
	mlx_loop(mlx->init);
	return (0);
}
