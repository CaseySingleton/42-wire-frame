/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:24:13 by csinglet          #+#    #+#             */
/*   Updated: 2018/06/25 19:24:14 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libmlx.h"

void		matrix_clear(float matrix[4][4])
{
	int		x;
	int		y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			matrix[y][x] = 0;
	}
}

void		matrix_init(float matrix[4][4])
{
	matrix_clear(matrix);
	matrix[0][0] = 1;
	matrix[1][1] = 1;
	matrix[2][2] = 1;
	matrix[3][3] = 1;
}

/*
**	if the dst matrix for matrix_multiply is also m1 or m2 function will
**	give incorrect values
*/

void		matrix_multiply(float dst[4][4], float m1[4][4], float m2[4][4])
{
	int		x;
	int		y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			dst[y][x] = m1[y][0] * m2[0][x] + m1[y][1] * m2[1][x] +
			m1[y][2] * m2[2][x] + m1[y][3] * m2[3][x];
	}
}

void		matrix_translate(float matrix[4][4], float x, float y, float z)
{
	float		translation_matrix[4][4];

	matrix_init(translation_matrix);
	translation_matrix[0][3] = x;
	translation_matrix[1][3] = y;
	translation_matrix[2][3] = z;
	matrix_multiply(matrix, translation_matrix, matrix);
}

void		matrix_set_scale(float matrix[4][4], float x, float y, float z)
{
	float		scale_matrix[4][4];

	matrix_init(scale_matrix);
	scale_matrix[0][0] = x;
	scale_matrix[1][1] = y;
	scale_matrix[2][2] = z;
	scale_matrix[3][3] = 1;
	matrix_multiply(matrix, scale_matrix, matrix);
}
