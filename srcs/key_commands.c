/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 19:40:23 by csinglet          #+#    #+#             */
/*   Updated: 2018/06/29 19:40:24 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
**	Not actually a key command but I needed a place to hold my rotation
**	function.
*/

void		rotate(t_mlx *mlx, float angle_x, float angle_y, float angle_z)
{
	int			mid_x;
	int			mid_y;
	float		rotate[4][4];

	mid_x = IMG_WIDTH / 2;
	mid_y = IMG_HEIGHT / 2;
	matrix_init(rotate);
	matrix_rotall(rotate, angle_x, angle_y, angle_z);
	offset_image(mlx, -mid_x, -mid_y, 0);
	apply_matrix_to_vectors(mlx, rotate);
	offset_image(mlx, mid_x, mid_y, 0);
}

/*
**	Bunch of if statements to catch keyboard input and apply a transformation
**	based on specific key inputs.
*/

void		use_key(t_mlx *mlx, int key)
{
	if (key == 53)
		exit(0);
	if (key == 0 || key == 2)
		rotate(mlx, 0, (key == 2) ? ANGLE : -ANGLE, 0);
	if (key == 13 || key == 1)
		rotate(mlx, (key == 13) ? ANGLE : -ANGLE, 0, 0);
	if (key == 12 || key == 14)
		rotate(mlx, 0, 0, (key == 14) ? ANGLE : -ANGLE);
	if (key == 69 || key == 78)
		scale_image(mlx, (key == 69) ? 1.2 : 0.8);
	if (key == 125 || key == 126)
		offset_image(mlx, 0, (key == 125) ? 10 : -10, 0);
	if (key == 123 || key == 124)
		offset_image(mlx, (key == 123) ? -10 : 10, 0, 0);
	use_image(mlx);
}
