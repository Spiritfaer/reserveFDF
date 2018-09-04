/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 21:49:28 by istalevs          #+#    #+#             */
/*   Updated: 2018/04/26 21:49:29 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		set_pixel(t_mlx *mlx, int x, int y, int color)
{
	x += mlx->map->center->x;
	y += mlx->map->center->y;
	if (x < 0 || y < 0 || x >= mlx->map->width || y >= mlx->map->height)
		return ;
	*(int*)(mlx->img_ptr->ptr + ((x + y * mlx->map->width)
									* mlx->img_ptr->bpp)) = color;
}

t_vector	*new_vector(int x, int y, char *zero)
{
	t_vector	*new;
	char		**tmp;

	if (!(new = (t_vector*)malloc(sizeof(t_vector))))
		return (NULL);
	new->x = x;
	new->y = y;
	new->flag = ft_splitter(zero, ',');
	if (new->flag == 2)
	{
		tmp = ft_strsplit(zero, ',');
		new->z = ft_atoi(tmp[0]);
		new->color = ft_atoi_base(tmp[1], 16);
		sf_split_del(tmp);
	}
	else
	{
		new->z = ft_atoi(zero);
		new->color = 0xFFFFFF;
	}
	return (new);
}

void		sf_relocate_point(t_map *map, t_vector *vector)
{
	if (!map || !vector)
		return ;
	vector->x -= map->center->x;
	vector->y -= map->center->y;
}

void		central(t_mlx *mlx, t_vector *vector)
{
	if (!mlx || !vector)
		return ;
	vector->x = (vector->x + (mlx->map->width / 2)) - (mlx->info->x_max / 2);
	vector->y = (vector->y + (mlx->map->height / 2)) - (mlx->info->y_max / 2);
}
