/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 23:54:23 by csinglet          #+#    #+#             */
/*   Updated: 2018/05/27 23:54:24 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "stdlib.h"

int			deal_key(int key, t_mlx *mlx)
{
	ft_putnbr(key);
	ft_putchar(' ');
	use_key(mlx, key);
	return (0);
}

int			initialize_mlx(t_mlx **mlx)
{
	if (!((*mlx) = (t_mlx *)malloc(sizeof(t_mlx))))
		return (-1);
	if (!((*mlx)->img = (t_img *)malloc(sizeof(t_img))))
		return (-1);
	if (!((*mlx)->cam = (t_cam *)malloc(sizeof(t_cam))))
		return (-1);
	return (0);
}

void		create_enviornment(t_mlx *mlx, int fd)
{
	build_map(mlx, fd);
	mlx->mlx_ptr = mlx_init();
	mlx->cam->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
										"42 Wire Frame");
	mlx->img->img_ptr = mlx_new_image(mlx->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	mlx->img->info = (int *)mlx_get_data_addr(mlx->img->img_ptr, &mlx->img->bpp,
	&mlx->img->len, &mlx->img->endian);
	offset_image(mlx, IMG_WIDTH / 2 - mlx->mw / 2 * OFFSET, IMG_HEIGHT /
				2 - mlx->mh / 2 * OFFSET, 0);
	draw_image(mlx->vm, mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->cam->win_ptr, mlx->img->img_ptr,
							0, 0);
	mlx_key_hook(mlx->cam->win_ptr, deal_key, mlx);
	mlx_loop(mlx->mlx_ptr);
}

int			main(int argc, char *argv[])
{
	t_mlx	*mlx;
	int		fd;

	if (initialize_mlx(&mlx) == -1)
		return (-1);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		create_enviornment(mlx, fd);
		while (1)
			;
	}
	return (0);
}
