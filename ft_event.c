/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 22:56:27 by istalevs          #+#    #+#             */
/*   Updated: 2018/04/26 22:56:29 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_reze(t_mlx *mlx, int key)
{
	if (key == 89)
		mlx->map->matrix->dz = 0.3;
	if (key == 91)
		mlx->map->matrix->dz = 0.5;
	if (key == 92)
		mlx->map->matrix->dz = 0.8;
	restore(mlx);
	mlx->map->scale = 20.0;
	mlx->map->matrix->rx = 0.9;
	mlx->map->center->x = mlx->map->width / 2;
	mlx->map->center->y = mlx->map->height / 2;
	ft_draw(mlx);
}

int			hook_keydown(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 69 && (mlx->map->scale += 0.1))
		ft_draw(mlx);
	if (key == 78 && (mlx->map->scale -= 0.1))
		ft_draw(mlx);
	if (key == 89)
		ft_reze(mlx, key);
	if (key == 91)
		ft_reze(mlx, key);
	if (key == 92)
		ft_reze(mlx, key);
	if (key == 126 && (mlx->map->matrix->ty -= 5.0))
		ft_draw(mlx);
	if (key == 125 && (mlx->map->matrix->ty += 5.0))
		ft_draw(mlx);
	if (key == 123 && (mlx->map->matrix->tx -= 5.0))
		ft_draw(mlx);
	if (key == 124 && (mlx->map->matrix->tx += 5.0))
		ft_draw(mlx);
	return (0);
}

int			hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	if (y < 0)
		return (0);
	mlx->mouse->isdown |= 1 << button;
	return (0);
}

int			hook_mouseup(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	mlx->mouse->isdown &= ~(1 << button);
	return (0);
}

int			hook_mousemove(int x, int y, t_mlx *mlx)
{
	mlx->mouse->lastx = mlx->mouse->x;
	mlx->mouse->lasty = mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	if (mlx->mouse->isdown & (1 << 1))
	{
		mlx->map->center->x += (x - mlx->mouse->lastx);
		mlx->map->center->y += (y - mlx->mouse->lasty);
		ft_draw(mlx);
	}
	if (mlx->mouse->isdown & (1 << 2))
	{
		mlx->map->matrix->ry -= (x - mlx->mouse->lastx) / 200.0f;
		mlx->map->matrix->rx += (y - mlx->mouse->lasty) / 200.0f;
		ft_draw(mlx);
	}
	return (0);
}
