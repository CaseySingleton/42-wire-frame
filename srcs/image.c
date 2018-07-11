/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 23:55:16 by csinglet          #+#    #+#             */
/*   Updated: 2018/05/27 23:55:17 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**	Function to organise the clutter that is placing images to the screen.
*/

void		use_image(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->cam->win_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img->img_ptr);
	mlx->img->img_ptr = mlx_new_image(mlx->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	draw_image(mlx->vm, mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->cam->win_ptr,
	mlx->img->img_ptr, 0, 0);
}

/*
**	Draw image iterates through the vector matrix and draws lines between
**	a vector located to the right and below the current vector.
**
**	If the x and y variables go are equal to the width of the map the result
**	will be extra lines being drawn on the right side and bottom of the image
*/

void		draw_image(t_vector **vector_map, t_mlx *mlx)
{
	int		x;
	int		y;

	y = -1;
	while (++y < mlx->mh)
	{
		x = -1;
		while (++x < mlx->mw)
		{
			if (x + 1 != mlx->mw)
				draw_line_to_image(mlx->img, vector_map[y][x],
				vector_map[y][x + 1]);
			if (y + 1 != mlx->mh)
				draw_line_to_image(mlx->img, vector_map[y][x],
				vector_map[y + 1][x]);
		}
	}
}

/*
**	Multiplies vectors by an offset matrix based on the desired offset
**	in the x, y and z direction.
*/

void		offset_image(t_mlx *mlx, int offset_x, int offset_y, int offset_z)
{
	float		offset_matrix[4][4];

	matrix_init(offset_matrix);
	matrix_translate(offset_matrix, offset_x, offset_y, offset_z);
	apply_matrix_to_vectors(mlx, offset_matrix);
}

/*
**	Multiplies vectors by a simple scaling matrix.
*/

void		scale_image(t_mlx *mlx, double scale)
{
	float		translation_matrix[4][4];

	offset_image(mlx, -IMG_WIDTH / 2, -IMG_HEIGHT / 2, 0);
	matrix_init(translation_matrix);
	matrix_set_scale(translation_matrix, scale, scale, scale);
	apply_matrix_to_vectors(mlx, translation_matrix);
	offset_image(mlx, IMG_WIDTH / 2, IMG_HEIGHT / 2, 0);
}

/*
**	Iteratres through the vector map and applies a matrix to each vector.
*/

void		apply_matrix_to_vectors(t_mlx *mlx, float matrix[4][4])
{
	int		x;
	int		y;

	y = -1;
	while (++y < mlx->mh)
	{
		x = -1;
		while (++x < mlx->mw)
			multiply_vector_by_matrix(&mlx->vm[y][x],
			matrix, &mlx->vm[y][x]);
	}
}
