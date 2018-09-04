/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 19:31:44 by istalevs          #+#    #+#             */
/*   Updated: 2018/04/26 19:31:47 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			sf_abs(int i)
{
	i = (i > 0) ? i : -i;
	return (i);
}

int			sf_max(int a, int b)
{
	return ((a > b ? a : b));
}

int			sf_error(char *str)
{
	ft_putendl(str);
	return (1);
}

void		sf_print_vectors(t_mlx *mlx)
{
	t_vector	**temp_vectors;
	int			i;
	int			max;

	temp_vectors = mlx->vect;
	i = 0;
	max = (sf_count_lst(mlx->list) * ft_splitter(mlx->list->content, ' '));
	while (i < max)
	{
		printf("i = %d = %f %f %f\n", i, temp_vectors[i]->x,
				temp_vectors[i]->y, temp_vectors[i]->z);
		i++;
	}
}

int			sf_checking_map(t_list *list)
{
	t_list	*tmp;
	int 	flag;

	tmp = list;
	while (tmp)
	{
		flag = ft_splitter(tmp->content, ' ');
		tmp = tmp->next;
		if (tmp && tmp->content && flag != ft_splitter(tmp->content, ' '))
			return (1);
	}
	return (0);
}
