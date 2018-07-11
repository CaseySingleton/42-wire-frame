/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 23:58:45 by csinglet          #+#    #+#             */
/*   Updated: 2018/05/27 23:58:45 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "../libmlx/includes/libmlx.h"
# include "../libft/get_next_line.h"

# include <stdio.h>

/*
**	kinda just filler stuff
*/

t_vector	fill_vec(int x, int y, int z);
void		cam_init(t_cam *cam);

/*
**	read functions
*/

/*
**	map functions
*/

void		build_map(t_mlx *mlx, int fd);
void		read_file(t_list **map, int fd);
void		get_vector_map(t_list **map, t_mlx *mlx);
void		delete_map(t_list **lst);

/*
**	image functinos
*/

void		draw_image(t_vector **vector_map, t_mlx *mlx);
void		offset_image(t_mlx *mlx, int offset_x, int offset_y, int offset_z);
void		scale_image(t_mlx *mlx, double scale);
void		use_image(t_mlx *mlx);
void		apply_matrix_to_vectors(t_mlx *mlx, float matrix[4][4]);

/*
**	key commands
*/

void		rotate(t_mlx *mlx, float angle_x, float angle_y, float angle_z);
void		use_key(t_mlx *mlx, int key);

#endif