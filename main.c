/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 19:31:13 by istalevs          #+#    #+#             */
/*   Updated: 2018/04/27 22:00:46 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			exit_x(void)
{
	exit(0);
}

int			main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 2)
		return (sf_error("error: should be two arguments"));
	if (!(mlx = new_mlx(ft_strjoin("FDF - ", argv[1]))))
		return (sf_error("error: invalid mlx"));
	if ((mlx->info->fd = open(argv[1], O_RDONLY)) <= 0)
		return (sf_error("error: invalid fd"));
	if (!sf_reader(mlx))
		return (sf_error("error: invalid map"));
	ft_draw(mlx);
	mlx_key_hook(mlx->win_ptr, hook_keydown, mlx);
	mlx_hook(mlx->win_ptr, 17, 1L << 17, exit_x, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, hook_mousedown, mlx);
	mlx_hook(mlx->win_ptr, 5, 0, hook_mouseup, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, hook_mousemove, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
