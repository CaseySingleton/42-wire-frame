/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:41:10 by csinglet          #+#    #+#             */
/*   Updated: 2018/06/25 19:41:11 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libmlx.h"

void		matrix_rotx_init(float matrix[4][4], float theta)
{
	matrix_clear(matrix);
	matrix[0][0] = 1;
	matrix[1][1] = cos(theta);
	matrix[1][2] = -sin(theta);
	matrix[2][1] = sin(theta);
	matrix[2][2] = cos(theta);
	matrix[3][3] = 1;
}

void		matrix_roty_init(float matrix[4][4], float theta)
{
	matrix_clear(matrix);
	matrix[0][0] = cos(theta);
	matrix[0][2] = sin(theta);
	matrix[1][1] = 1;
	matrix[2][0] = -sin(theta);
	matrix[2][2] = cos(theta);
	matrix[3][3] = 1;
}

void		matrix_rotz_init(float matrix[4][4], float theta)
{
	matrix_clear(matrix);
	matrix[0][0] = cos(theta);
	matrix[0][1] = -sin(theta);
	matrix[1][0] = sin(theta);
	matrix[1][1] = cos(theta);
	matrix[2][2] = 1;
	matrix[3][3] = 1;
}

void		matrix_rotall(float matrix[4][4], float theta_x,
			float theta_y, float theta_z)
{
	float	rotx[4][4];
	float	roty[4][4];
	float	rotz[4][4];
	float	temp1[4][4];
	float	temp2[4][4];

	matrix_rotx_init(rotx, theta_x);
	matrix_roty_init(roty, theta_y);
	matrix_rotz_init(rotz, theta_z);
	matrix_multiply(temp1, rotx, matrix);
	matrix_multiply(temp2, roty, temp1);
	matrix_multiply(matrix, rotz, temp2);
}

void		multiply_vector_by_matrix(t_vector *dst_vector,
			float matrix[4][4], t_vector *vector)
{
	float x;
	float y;
	float z;

	x = vector->x * matrix[0][0] + vector->y * matrix[0][1] +
		vector->z * matrix[0][2] + matrix[0][3];
	y = vector->x * matrix[1][0] + vector->y * matrix[1][1] +
		vector->z * matrix[1][2] + matrix[1][3];
	z = vector->x * matrix[2][0] + vector->y * matrix[2][1] +
		vector->z * matrix[2][2] + matrix[2][3];
	dst_vector->x = x;
	dst_vector->y = y;
	dst_vector->z = z;
}
