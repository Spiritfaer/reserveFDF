/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 19:36:40 by istalevs          #+#    #+#             */
/*   Updated: 2018/04/27 22:23:56 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
	int				color;
	int				flag;
	struct s_vector	*save;
}					t_vector;

typedef struct		s_line
{
	int			distance;
	int			deltax;
	int			deltay;
	int			x;
	int			y;
	int			xerr;
	int			yerr;
	int			incx;
	int			incy;
	int			s_color;
	int			end_color;
}					t_line;

typedef struct		s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			size_line;
	int			endian;
}					t_image;

typedef struct		s_info
{
	int			fd;
	char		*win_name;
	int			x_max;
	int			y_max;
}					t_info;

typedef struct		s_matrix
{
	double		tx;
	double		ty;
	double		tz;
	double		rx;
	double		ry;
	double		dz;
}					t_matrix;

typedef struct		s_map
{
	int			width;
	int			height;
	double		scale;
	int			d_max;
	int			d_min;
	t_matrix	*matrix;
	t_vector	*center;
}					t_map;

typedef struct		s_mouse
{
	int			isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}					t_mouse;

typedef struct		s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_info		*info;
	t_map		*map;
	t_list		*list;
	t_image		*img_ptr;
	t_vector	**vect;
	t_mouse		*mouse;
}					t_mlx;

int					sf_checking_map(t_list *list);
void				ft_reset_matrix(t_map *map, t_mlx *mlx);
int					exit_x(void);
int					ft_atoi_base(const char *str, int str_base);
void				ft_draw(t_mlx *mlx);
void				*sf_reader(t_mlx *mlx);
void				sf_prepare(t_mlx *mlx);
void				sf_save_first_point(t_vector *vectors);
void				sf_make_lst_vectors(t_mlx *mlx, t_list *tmp);
void				sf_set_depth(int *min, int *max, t_vector *v);
int					sf_abs(int i);
int					sf_max(int a, int b);
int					sf_error(char *str);
void				sf_print_vectors(t_mlx *mlx);
void				set_map(t_map *map);
void				set_mouse(t_mouse *mouse);
t_mlx				*set_mlx(void);
t_image				*new_image(t_mlx *mlx);
t_mlx				*new_mlx(char *str);
t_mlx				*sf_del_mlx(t_mlx *mlx, char *str);
t_image				*sf_del_img(t_image **img, t_mlx *mlx);
void				sf_print_list(t_list *head);
int					sf_count_lst(t_list *head);
void				sf_rev_list(t_list **head);
void				sf_split_del(char **str);
t_vector			*new_vector(int x, int y, char *zero);
void				set_pixel(t_mlx *mlx, int x, int y, int color);
void				sf_relocate_point(t_map *map, t_vector *vector);
void				central(t_mlx *mlx, t_vector *vector);
void				restore(t_mlx *mlx);
void				move(t_mlx *mlx, t_vector *vector);
void				scale(t_mlx *mlx, t_vector *vector);
void				rotation(t_mlx *mlx, t_vector *v);
void				sf_matrix(t_mlx *mlx);
t_line				*sf_give_line(t_vector *p1, t_vector *p2);
void				draw_line(t_mlx *mlx, t_line *line, int iter);
void				line_brazenhaim(t_mlx *mlx, t_vector *p1, t_vector *p2);
void				color(t_mlx *mlx, t_vector *v);
int					set_red(int color_1, int color_2, double l, int iter);
int					set_green(int color_1, int color_2, double l, int iter);
int					set_blue(int color_1, int color_2, double l, int iter);
int					sf_line_color(double length, int iter,
									int color_1, int color_2);
int					hook_keydown(int key, t_mlx *mlx);
int					hook_mousedown(int button, int x, int y, t_mlx *mlx);
int					hook_mouseup(int button, int x, int y, t_mlx *mlx);
int					hook_mousemove(int x, int y, t_mlx *mlx);
void				ft_reze(t_mlx *mlx, int key);
#endif
