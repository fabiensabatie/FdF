/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:42:38 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/08 11:09:17 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WINX 1440
# define WINY 900


typedef struct	s_dot
{
	int			x;
	int			y;
	int			color;
}				t_dot;

typedef struct s_map
{
	int			**map;
	int			height;
	int			width;
	int			tile_width;
	int			tile_height;
	int			offx;
	int			offy;
	int			zplus;
}				t_map;

typedef struct	s_mlx_infos
{
	void 		*init;
	void 		*window;
	t_map		*map;
}				t_mlx_infos;

t_mlx_infos	*new_mlx_infos(int win_x, int win_y, char *title);
t_dot		*new_dot(int x, int y, int color);
void		print_line(t_mlx_infos *mlx, t_dot *start, t_dot *end);
void		ft_swapdots(t_dot *a, t_dot *b);
void		ft_swapdotcoor(t_dot *dot);
void		draw_map(t_mlx_infos *mlx, t_map *map);
t_map		*get_map(char *filename);
int			handle_events(int keycode, t_mlx_infos* map);
int			get_color(int z);

#endif