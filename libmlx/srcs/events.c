/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:53:39 by csinglet          #+#    #+#             */
/*   Updated: 2018/06/06 16:53:41 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

/*
**	To recieve events the mlx_loop() function must be used. The mlx_loop()
**	You can assign defferent functions to the three following events:
**	- A key is pressed
**	- A mouse button is pressed
**	- A part of the window should be re-drawn. This is called an expose event
**	  and it is your job to handle it
**
**	Events are unique to each window
*/

/*
**	function is an infinite loop
**	int mlx_loop(void *mlx)
**	int mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param)
**	int mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param)
**	int mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param)
**	int mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param)
**		Called when no event occures
*/

/*
** function that will close the window if esc is pressed or window is closed
*/
