/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 22:48:57 by istalevs          #+#    #+#             */
/*   Updated: 2018/04/26 22:48:58 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		color(t_mlx *mlx, t_vector *v)
{
	float length;

	if (!mlx || !v)
		return ;
	length = abs(mlx->map->d_max - mlx->map->d_min);
	if (v->flag == 1)
		v->color = sf_line_color(length, (int)v->z, 0xFF0000, 0xFFFFFF);
}

int			set_red(int color_1, int color_2, double l, int iter)
{
	int new_red;

	if ((int)l < iter)
		return (color_2);
	color_1 = ((color_1 >> 16) & 0xFF);
	color_2 = ((color_2 >> 16) & 0xFF);
	new_red = (int)(color_2 * (iter / l) + color_1 * ((l - iter) / l));
	if (new_red >= 0xFF && new_red < 0xFFF)
		new_red = 0xFF;
	if (new_red > 0xFFF)
		new_red = 0;
	return (((new_red << 16) & 0xFF0000));
}

int			set_green(int color_1, int color_2, double l, int iter)
{
	int new_green;

	if ((int)l < iter)
		return (color_2);
	color_1 = ((color_1 >> 8) & 0xFF);
	color_2 = ((color_2 >> 8) & 0xFF);
	new_green = (int)(color_2 * (iter / l) + color_1 * ((l - iter) / l));
	if (new_green >= 0xFF && new_green < 0xFFF)
		new_green = 0xFF;
	if (new_green > 0xFFF)
		new_green = 0;
	return (((new_green << 8) & 0x00FF00));
}

int			set_blue(int color_1, int color_2, double l, int iter)
{
	int new_blue;

	if ((int)l < iter)
		return (color_2);
	color_1 &= 0xFF;
	color_2 &= 0xFF;
	new_blue = (int)(color_2 * (iter / l) + color_1 * ((l - iter) / l));
	if (new_blue >= 0xFF && new_blue < 0xFFF)
		new_blue = 0xFF;
	if (new_blue > 0xFFF)
		new_blue = 0;
	return ((new_blue & 0xFF));
}

int			sf_line_color(double length, int iter, int color_1, int color_2)
{
	int r;
	int g;
	int b;
	int new_color;

	if (length < 2.0)
		return (color_2);
	new_color = 0;
	r = set_red(color_1, color_2, length, iter);
	g = set_green(color_1, color_2, length, iter);
	b = set_blue(color_1, color_2, length, iter);
	new_color |= r;
	new_color |= g;
	new_color |= b;
	return (new_color);
}
