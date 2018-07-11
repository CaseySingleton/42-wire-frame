/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 22:06:22 by csinglet          #+#    #+#             */
/*   Updated: 2018/07/10 17:56:05 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMLX_H
# define LIBMLX_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# define WHITE 0xffffff
# define BLACK 0x000000
# define RED 0xff0000
# define BLUE 0x0000ff
# define GREEN 0x00ff00

# define WIN_HEIGHT 1200
# define WIN_WIDTH 1600
# define IMG_HEIGHT 1200
# define IMG_WIDTH 1600
# define OFFSET 10
# define ANGLE M_PI / 16
# define ISO_ANGLE M_PI / 4

/*
**	The cam struct is used to store scale and rotation values so that when a
**	new image is created via the master copy it will be created with the
**	proper rotation, position and scale.
*/

typedef struct			s_cam
{
	double				theta_x;
	double				theta_y;
	double				theta_z;
	double				offset;
	double				scale;
	void				*win_ptr;
}						t_cam;

/*
**	The vector struct used to hold x, y and z values to represent a 3D point.
*/

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
}						t_vector;

/*
**	The line struct is mostly for organising and reducing the number of
**	variables used when drawing a line.
*/

typedef struct          s_line
{
	double				diff_x;
	double				diff_y;
	double				diff_z;
	double				slope;
	double				error;
}						t_line;

/*
**	The img struct is used for organising variables needed to use to MLX
**	library.
**
**	bpp - bytes per pixel.
**	len - length of each line of pixels. Equal to the horizontal resolution.
**	endian - I have no idea really.
*/

typedef struct			s_img
{
	void				*img_ptr;
	int					*info;
	int					bpp;
	int					len;
	int					endian;
}						t_img;

/*
**	Parent structure containing pointers to other structures. Also hold
**	the vector map and map width/height
*/

typedef struct			s_mlx
{
	t_vector			**vm;
	t_img				*img;
	t_cam				*cam;
	void				*mlx_ptr;
	int					mh;
	int					mw;
}						t_mlx;

/*
**	draw.c
*/

void		draw_point(t_mlx *mlx, int x, int y, int color);
void		draw_point_to_image(t_img *img, int x, int y, int color);
int			swap_value(t_vector *p1, t_vector *p2);
void		draw_line(t_mlx *mlx, t_vector p1, t_vector p2);
void		draw_line_to_image(t_img *img, t_vector p1, t_vector p2);

/*
**	matrix_rotation.c
*/

void		matrix_rotx_init(float matrix[4][4], float theta);
void		matrix_roty_init(float matrix[4][4], float theta);
void		matrix_rotz_init(float matrix[4][4], float theta);
void		matrix_rotall(float matrix[4][4], float theta_x, float theta_y, float theta_z);
void		multiply_vector_by_matrix(t_vector *dst_vector, float matrix[4][4], t_vector *vector);

/*
**	matrix_management.c
*/

void		matrix_clear(float matrix[4][4]);
void		matrix_init(float matrix[4][4]);
void		matrix_multiply(float dst[4][4], float m1[4][4], float m2[4][4]);
void		matrix_translate(float matrix[4][4], float x, float y, float z);
void		matrix_set_scale(float matrix[4][4], float x, float y, float z);

#endif
