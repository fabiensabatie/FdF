/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:24:37 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/01 15:24:38 by fsabatie         ###   ########.fr       */
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
	get_map(argv[1]);
	mlx = new_mlx_infos(600, 600, "FDF FTW");
	mlx_loop(mlx->init);
	return (0);
}
