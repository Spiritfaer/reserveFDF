/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brazenhaim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 22:42:35 by istalevs          #+#    #+#             */
/*   Updated: 2018/04/26 22:42:36 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line		*sf_give_line(t_vector *p1, t_vector *p2)
{
	t_line	*newline;

	if (!(newline = (t_line*)malloc(sizeof(t_line))))
		return (NULL);
	newline->distance = 0;
	newline->deltax = (int)(p2->x - p1->x);
	newline->deltay = (int)(p2->y - p1->y);
	newline->x = (int)p1->x;
	newline->y = (int)p1->y;
	newline->xerr = 0;
	newline->yerr = 0;
	newline->incx = 0;
	newline->incy = 0;
	newline->s_color = p1->color;
	newline->end_color = p2->color;
	return (newline);
}

void		draw_line(t_mlx *mlx, t_line *line, int iter)
{
	int		color;

	color = sf_line_color(line->distance, iter, line->s_color, line->end_color);
	set_pixel(mlx, line->x, line->y, color);
	line->xerr += line->deltax;
	line->yerr += line->deltay;
	if (line->xerr > line->distance)
	{
		line->xerr -= line->distance;
		line->x += line->incx;
	}
	if (line->yerr > line->distance)
	{
		line->yerr -= line->distance;
		line->y += line->incy;
	}
}

void		line_brazenhaim(t_mlx *mlx, t_vector *p1, t_vector *p2)
{
	t_line	*line;
	int		t;

	if (!(line = sf_give_line(p1, p2)))
		return ;
	if (line->deltax > 0)
		line->incx = 1;
	else if (line->deltax == 0)
		line->incx = 0;
	else
		line->incx = -1;
	if (line->deltay > 0)
		line->incy = 1;
	else if (line->deltay == 0)
		line->incy = 0;
	else
		line->incy = -1;
	line->deltax = sf_abs(line->deltax);
	line->deltay = sf_abs(line->deltay);
	line->distance = sf_max(line->deltax, line->deltay);
	t = 0;
	while (t <= line->distance + 1)
		draw_line(mlx, line, t++);
	free(line);
}
