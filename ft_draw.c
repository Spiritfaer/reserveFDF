/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 22:17:13 by istalevs          #+#    #+#             */
/*   Updated: 2018/04/27 22:12:10 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_reset_matrix(t_map *map, t_mlx *mlx)
{
	map->matrix->tx = 0;
	map->matrix->ty = 0;
	map->matrix->rx = 0.0;
	map->matrix->ry = 0.0;
	map->matrix->dz = 1.0;
	map->scale = 1;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
							mlx->img_ptr->image, 0, 0);
}

void		ft_draw(t_mlx *mlx)
{
	int			x;
	int			y;
	t_vector	*p1;
	t_vector	*p2;

	sf_matrix(mlx);
	y = 0;
	while (y < mlx->info->y_max)
	{
		x = 0;
		while (x < mlx->info->x_max)
		{
			p1 = mlx->vect[x + y * mlx->info->x_max];
			if (x + 1 < mlx->info->x_max
				&& (p2 = mlx->vect[x + 1 + y * mlx->info->x_max]))
				line_brazenhaim(mlx, p1, p2);
			if (y + 1 < mlx->info->y_max
				&& (p2 = mlx->vect[x + (y + 1) * mlx->info->x_max]))
				line_brazenhaim(mlx, p1, p2);
			x++;
		}
		y++;
	}
	ft_reset_matrix(mlx->map, mlx);
}
