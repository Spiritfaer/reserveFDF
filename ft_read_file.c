/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 21:27:57 by istalevs          #+#    #+#             */
/*   Updated: 2018/04/27 22:06:22 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		sf_set_depth(int *min, int *max, t_vector *v)
{
	if (!min || !max || !v)
		return ;
	if (*max < v->z)
		*max = (int)v->z;
	if (*min > v->z)
		*min = (int)v->z;
}

void		sf_make_lst_vectors(t_mlx *mlx, t_list *tmp)
{
	char	**str;
	int		x;
	int		y;

	if (!(mlx->vect = (t_vector **)malloc(sizeof(t_vector)
		* (mlx->info->x_max * mlx->info->y_max + (size_t)1))))
		return ;
	ft_bzero(mlx->vect, mlx->info->x_max * mlx->info->y_max + (size_t)1);
	y = 0;
	while (y < mlx->info->y_max)
	{
		str = ft_strsplit(tmp->content, ' ');
		x = 0;
		while (x < mlx->info->x_max)
		{
			mlx->vect[x + y * mlx->info->x_max] = new_vector(x, y, str[x]);
			sf_set_depth(&mlx->map->d_min, &mlx->map->d_max,
						mlx->vect[x + y * mlx->info->x_max]);
			x++;
		}
		sf_split_del(str);
		y++;
		tmp = tmp->next;
	}
}

void		sf_save_first_point(t_vector *vectors)
{
	if (!vectors || !(vectors->save = (t_vector*)malloc(sizeof(t_vector))))
		return ;
	vectors->save->x = vectors->x;
	vectors->save->y = vectors->y;
	vectors->save->z = vectors->z;
	vectors->save->color = vectors->color;
	vectors->save->flag = vectors->flag;
	vectors->save->save = NULL;
}

void		sf_prepare(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y < mlx->info->y_max)
	{
		x = 0;
		while (x < mlx->info->x_max)
		{
			central(mlx, mlx->vect[x + y * mlx->info->x_max]);
			sf_relocate_point(mlx->map, mlx->vect[x + y * mlx->info->x_max]);
			sf_save_first_point(mlx->vect[x + y * mlx->info->x_max]);
			color(mlx, mlx->vect[x + y * mlx->info->x_max]);
			x++;
		}
		y++;
	}
}

void		*sf_reader(t_mlx *mlx)
{
	char	*line;
	size_t	test_count;

	test_count = 0;
	if (!mlx)
		return (NULL);
	while ((get_next_line(mlx->info->fd, &line)) > 0)
	{
		ft_lstadd(&mlx->list, ft_lstnew(line, ft_strlen(line) + 1));
		test_count += ft_splitter(line, ' ');
		free(line);
	}
	if (sf_checking_map(mlx->list))
		return (sf_del_mlx(mlx, mlx->info->win_name));
	mlx->info->x_max = ft_splitter(mlx->list->content, ' ');
	mlx->info->y_max = sf_count_lst(mlx->list);
	sf_rev_list(&mlx->list);
	sf_make_lst_vectors(mlx, mlx->list);
	close(mlx->info->fd);
	sf_prepare(mlx);
	return (mlx);
}
