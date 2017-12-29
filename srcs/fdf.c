/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:24:37 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/24 18:32:12 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../libft/libft.h"
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

int					main(int argc, char **argv)
{
	t_mlx_infos	*mlx;
	char		*title;

	if (argc != 2)
		ft_putnexit("usage : ./fdf [map]");
	title = ft_strjoin("FDF - ", argv[1]);
	mlx = new_mlx_infos(WINX, WINY, title);
	mlx->map = get_map(argv[1]);
	draw_map(mlx, mlx->map);
	mlx_key_hook(mlx->window, handle_events, mlx);
	mlx_loop(mlx->init);
	free(title);
	return (0);
}
