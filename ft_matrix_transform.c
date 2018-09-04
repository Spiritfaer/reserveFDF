/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_transform.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 22:32:22 by istalevs          #+#    #+#             */
/*   Updated: 2018/04/27 22:00:15 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void		restore(t_mlx *mlx)
{
	int			x;
	int			y;
	t_vector	*p1;
	t_vector	*p2;

	y = 0;
	while (y < mlx->info->y_max)
	{
		x = 0;
		while (x < mlx->info->x_max)
		{
			p1 = mlx->vect[x + y * mlx->info->x_max];
			p2 = mlx->vect[x + y * mlx->info->x_max]->save;
			p1->x = p2->x;
			p1->y = p2->y;
			p1->z = p2->z;
			x++;
		}
		y++;
	}
}

void		move(t_mlx *mlx, t_vector *vector)
{
	if (!mlx || !vector)
		return ;
	vector->x += mlx->map->matrix->tx;
	vector->y += mlx->map->matrix->ty;
	vector->z += mlx->map->matrix->tz;
}

void		scale(t_mlx *mlx, t_vector *vector)
{
	if (!mlx || !vector)
		return ;
	vector->x *= mlx->map->scale;
	vector->y *= mlx->map->scale;
	vector->z *= mlx->map->scale * mlx->map->matrix->dz;
}

void		rotation(t_mlx *mlx, t_vector *v)
{
	t_vector t;

	if (!mlx || !v)
		return ;
	t.x = v->x;
	t.y = v->y;
	t.z = v->z;
	t.x = cos(mlx->map->matrix->ry) * v->x + sin(mlx->map->matrix->ry) * v->z;
	t.z = -sin(mlx->map->matrix->ry) * v->x + cos(mlx->map->matrix->ry) * v->z;
	t.y = cos(mlx->map->matrix->rx) * v->y - sin(mlx->map->matrix->rx) * t.z;
	t.z = sin(mlx->map->matrix->rx) * v->y + cos(mlx->map->matrix->rx) * t.z;
	v->x = t.x;
	v->y = t.y;
	v->z = t.z;
}

void		sf_matrix(t_mlx *mlx)
{
	int	x;
	int y;

	y = 0;
	bzero(mlx->img_ptr->ptr, mlx->img_ptr->size_line * mlx->map->height);
	while (y < mlx->info->y_max)
	{
		x = 0;
		while (x < mlx->info->x_max)
		{
			scale(mlx, mlx->vect[x + y * mlx->info->x_max]);
			rotation(mlx, mlx->vect[x + y * mlx->info->x_max]);
			move(mlx, mlx->vect[x + y * mlx->info->x_max]);
			x++;
		}
		y++;
	}
}
