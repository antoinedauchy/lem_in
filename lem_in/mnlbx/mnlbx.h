/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mnlbx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 04:50:16 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/22 23:47:54 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MNLBX_H
# define MNLBX_H

# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"

# define ECHAP	53
# define UP		126
# define DOWN	125
# define LEFT	123
# define RIGHT	124
# define W		13
# define A		0
# define S		1
# define D		2

typedef struct	s_coord
{
	int			x;
	int			y;
	int			color;
}				t_coord;

typedef struct	s_poly
{
	t_coord		a;
	t_coord		b;
	t_coord		c;
	t_coord		d;
}				t_poly;

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpb;
	int			sizeline;
	int			endian;
	int			height;
	int			lenght;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			height_win;
	int			lenght_win;
}				t_mlx;

typedef struct	s_line
{
	int			dist_x;
	int			dist_y;
	int			dist;
	int			nb;
}				t_line;

int				init_mlx(t_mlx *data, int lenght, int height, char *title);
int				load_img(t_img *img, void *mlx, char *name);
int				key_hook(int keycode, void *ptr);
int				put_pxl_img(t_coord coord, t_img img);
int				loop_hook(void *ptr);
void			fill_image(t_img img, int color);
void			print_square(t_coord pos, t_coord size,
					int color, t_img img);
void			print_trans_img(t_img dest, t_img src,
					t_coord pos, t_coord size);
void			print_trans_color_img(t_img dest, t_img src,
					t_coord pos, t_coord size);
void			print_way(t_coord a, t_coord b, int width, t_img img);
void			print_line(t_coord a, t_coord b, t_img img);
void			print_polygone(t_poly poly, t_img img);
int				get_color(int nb, int start, int end, int diff);

#endif
