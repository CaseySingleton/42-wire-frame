/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:52:01 by csinglet          #+#    #+#             */
/*   Updated: 2018/05/30 20:52:02 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"

/*
**	Creates and initializes (statically) the x, y, and z variables of a vector
**	and then returns the vector.
*/

t_vector	fill_vec(int x, int y, int z)
{
	t_vector		new_coord;

	new_coord.x = x;
	new_coord.y = y;
	new_coord.z = z;
	return (new_coord);
}

/*
**	My fdf as it currently is does not support or use the functionality
**	of the t_cam structure. It is here for later use when I do not have the
**	luxury of sacrificing speed for accuacy.
*/

void		cam_init(t_cam *cam)
{
	float		angle;

	angle = M_PI / 4;
	cam->theta_x = angle;
	cam->theta_y = angle;
	cam->theta_z = angle;
	cam->scale = 1;
}
