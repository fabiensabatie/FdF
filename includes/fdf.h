/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:42:38 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/01 18:42:39 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WINX 600
# define WINY 600

typedef struct	s_mlx_infos
{
	void 		*init;
	void 		*window;
}				t_mlx_infos;

typedef struct	s_dot
{
	int			x;
	int			y;
	int			color;
}				t_dot;

t_mlx_infos	*new_mlx_infos(int win_x, int win_y, char *title);
t_dot		*new_dot(int x, int y, int color);
void		print_line(t_mlx_infos *mlx, t_dot *start, t_dot *end);
void		ft_swapdots(t_dot *a, t_dot *b);
void		ft_swapdotcoor(t_dot *dot);
void		get_map(char *filename);

#endif