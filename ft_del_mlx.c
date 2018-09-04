/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 19:41:23 by istalevs          #+#    #+#             */
/*   Updated: 2018/04/26 19:41:24 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx		*sf_del_mlx(t_mlx *mlx, char *str)
{
	if (mlx->info != NULL)
		ft_memdel((void **)&mlx->info);
	if (mlx->map != NULL)
		ft_memdel((void **)&mlx->map);
	if (str != NULL)
		ft_memdel((void **)&str);
	if (mlx->mouse != NULL)
		ft_memdel((void **)&mlx->mouse);
	if (mlx->win_ptr != NULL)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->img_ptr != NULL)
		sf_del_img(&mlx->img_ptr, mlx);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_image		*sf_del_img(t_image **img, t_mlx *mlx)
{
	if ((*img) != NULL)
	{
		if ((*img)->ptr != NULL)
			mlx_destroy_image(mlx->mlx_ptr, (*img)->image);
		ft_memdel((void **)&(*img));
	}
	return (NULL);
}
