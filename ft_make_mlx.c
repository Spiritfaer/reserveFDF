/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 19:39:35 by istalevs          #+#    #+#             */
/*   Updated: 2018/04/27 22:12:58 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		set_map(t_map *map)
{
	map->width = 960;
	map->height = 540;
	map->matrix = (t_matrix*)malloc(sizeof(t_matrix));
	map->matrix->tx = 0;
	map->matrix->ty = 0;
	map->matrix->tz = 0;
	map->matrix->rx = 1.25;
	map->matrix->ry = 0.0;
	map->matrix->dz = 1.0;
	map->scale = 20.0;
	map->d_max = 0;
	map->d_min = 0;
	map->center = (t_vector*)malloc(sizeof(t_vector));
	map->center->x = map->width / 2;
	map->center->y = map->height / 2;
	map->center->z = 0;
	map->center->color = 0xFF0000;
}

void		set_mouse(t_mouse *mouse)
{
	mouse->x = 0;
	mouse->y = 0;
	mouse->lastx = 0;
	mouse->lasty = 0;
}

t_mlx		*set_mlx(void)
{
	t_mlx *new_mlx;

	if (!(new_mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		return (NULL);
	new_mlx->info = NULL;
	new_mlx->map = NULL;
	new_mlx->list = NULL;
	new_mlx->img_ptr = NULL;
	new_mlx->vect = NULL;
	new_mlx->mouse = NULL;
	new_mlx->win_ptr = NULL;
	new_mlx->img_ptr = NULL;
	return (new_mlx);
}

t_image		*new_image(t_mlx *mlx)
{
	t_image		*new_image;

	if (!(new_image = (t_image*)malloc(sizeof(t_image))))
		return (NULL);
	if (!(new_image->image = mlx_new_image(mlx->mlx_ptr,
			mlx->map->width, mlx->map->height)))
		return (sf_del_img(&new_image, mlx));
	if (!(new_image->ptr = mlx_get_data_addr(new_image->image,
											&new_image->bpp,
											&new_image->size_line,
											&new_image->endian)))
		return (sf_del_img(&new_image, mlx));
	new_image->bpp /= 8;
	return (new_image);
}

t_mlx		*new_mlx(char *str)
{
	t_mlx	*new_mlx;

	if (!(new_mlx = set_mlx()))
		return (NULL);
	if (!(new_mlx->mlx_ptr = mlx_init()))
		return (sf_del_mlx(new_mlx, str));
	if (!(new_mlx->info = (t_info*)malloc(sizeof(t_info))))
		return (sf_del_mlx(new_mlx, str));
	if (!(new_mlx->map = (t_map*)malloc(sizeof(t_map))))
		return (sf_del_mlx(new_mlx, str));
	set_map(new_mlx->map);
	if (!(new_mlx->mouse = (t_mouse*)malloc(sizeof(t_mouse))))
		return (sf_del_mlx(new_mlx, str));
	set_mouse(new_mlx->mouse);
	if (!(new_mlx->win_ptr = mlx_new_window(new_mlx->mlx_ptr,
				new_mlx->map->width, new_mlx->map->height, str)))
		return (sf_del_mlx(new_mlx, str));
	if (!(new_mlx->img_ptr = new_image(new_mlx)))
		return (sf_del_mlx(new_mlx, str));
	new_mlx->info->win_name = str;
	return (new_mlx);
}
