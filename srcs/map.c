/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 23:54:01 by csinglet          #+#    #+#             */
/*   Updated: 2018/05/27 23:54:02 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"

void		build_map(t_mlx *mlx, int fd)
{
	t_list		*map;

	map = NULL;
	read_file(&map, fd);
	get_vector_map(&map, mlx);
	delete_map(&map);
}

void		read_file(t_list **map, int fd)
{
	t_list		*temp;
	char		*file_info;
	int			ret;

	while ((ret = get_next_line(fd, &file_info) != 0))
	{
		temp = ft_lstnew(file_info, ft_strlen(file_info) + 1);
		if (temp == NULL)
			return ;
		ft_lstadd_end(map, temp);
		free(file_info);
		file_info = NULL;
	}
}

void		get_vector_map(t_list **map, t_mlx *mlx)
{
	char		**split;
	t_list		*cur;
	int			i;
	int			j;

	cur = *map;
	mlx->mh = ft_lstlen(cur);
	mlx->mw = ft_wrdcount(cur->content, ' ');
	if (!(mlx->vm = (t_vector **)malloc(sizeof(t_vector *) * mlx->mh)))
		return ;
	i = -1;
	while (++i < mlx->mh)
	{
		if (!(mlx->vm[i] = (t_vector *)malloc(sizeof(t_vector) * mlx->mw)))
			return ;
		split = ft_strsplit(cur->content, ' ');
		j = -1;
		while (++j < mlx->mw)
		{
			mlx->vm[i][j] = fill_vec(j * OFFSET, i * OFFSET, atoi(split[j]));
			free(split[j]);
		}
		free(split);
		cur = cur->next;
	}
}

void		delete_map(t_list **lst)
{
	t_list		*cur;
	t_list		*next;
	int			count;

	cur = *lst;
	count = 0;
	while (cur)
	{
		next = cur->next;
		ft_bzero(cur->content, ft_strlen(cur->content));
		free(cur->content);
		free(cur);
		cur = next;
	}
}
