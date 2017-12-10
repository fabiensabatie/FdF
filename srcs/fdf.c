/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:24:37 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/08 12:09:58 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../includes/libft/libft.h"
#include "../includes/fdf.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
	t_mlx_infos *mlx;

	if (argc != 2)
		exit(1);
	mlx = new_mlx_infos(WINX, WINY, ft_strjoin("FDF - ", argv[1]));

	mlx->map = get_map(argv[1]);
	draw_map(mlx, mlx->map);
	mlx_do_key_autorepeaton(mlx->init);
	mlx_key_hook(mlx->window, handle_events, mlx);
	mlx_loop(mlx->init);
	return (0);
}
