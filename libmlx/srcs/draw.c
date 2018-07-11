/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 21:51:58 by csinglet          #+#    #+#             */
/*   Updated: 2018/07/10 17:54:42 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libmlx.h"

void		draw_point(t_mlx *mlx, int x, int y, int color)
{
	if (x > 0 && x < IMG_WIDTH && y > 0 && y < IMG_HEIGHT)
		return ;
	mlx_pixel_put(mlx->mlx_ptr, mlx->cam->win_ptr, x, y, color);
}

void		draw_point_to_image(t_img *img, int x, int y, int color)
{
	int			location;

	if (x < 0 || x > IMG_WIDTH || y < 0 || y > IMG_HEIGHT)
		return ;
	location = x + (y * img->len / 4);
	if (location < IMG_WIDTH * IMG_HEIGHT)
		img->info[location] = color;
}

int			swap_value(t_vector *p1, t_vector *p2)
{
	int			temp;

	temp = 0;
	if (fabs(p2->x - p1->x) > fabs(p2->y - p1->y))
		return (0);
	temp = p1->x;
	p1->x = p1->y;
	p1->y = temp;
	temp = p2->y;
	p2->y = p2->x;
	p2->x = temp;
	return (1);
}

void		draw_line(t_mlx *mlx, t_vector p1, t_vector p2)
{
	t_line		line;
	int			swap;

	swap = swap_value(&p1, &p2);
	line.diff_x = p2.x - p1.x;
	line.diff_y = p2.y - p1.y;
	line.slope = fabs(line.diff_y - line.diff_x);
	line.error = -1;
	while (p1.x != p2.x)
	{
		draw_point(mlx, swap ? p1.y : p1.x, swap ? p1.x : p1.y, WHITE);
		line.error += line.slope;
		if (line.error >= 0)
		{
			p1.y += (p1.y > p2.y) ? -1 : 1;
			line.error -= line.diff_x;
		}
		p1.x += (p1.x > p2.x) ? -1 : 1;
	}
}

void		draw_line_to_image(t_img *img, t_vector p1, t_vector p2)
{
	t_line		line;
	int			swap;

	swap = swap_value(&p1, &p2);
	line.diff_x = p2.x - p1.x;
	line.diff_y = p2.y - p1.y;
	line.diff_z = p2.z - p1.z;
	line.slope = fabs(line.diff_y / line.diff_x);
	line.error = -1;
	while ((int)p1.x != (int)p2.x)
	{
		draw_point_to_image(img, swap ? p1.y : p1.x, swap ? p1.x : p1.y, 0x42d0d6);
		line.error += line.slope;
		if ((int)line.error >= 0)
		{
			p1.y += (p1.y > p2.y) ? -1 : 1;
			line.error -= 1;
		}
		p1.z += line.diff_z / fabs(line.diff_x);
		p1.x += (p1.x > p2.x) ? -1 : 1;
	}
}
