/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 08:01:07 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/25 23:59:33 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init(t_af *p)
{
	p->deep = 0;
	p->tight = 0;
	p->tight2 = 0;
	p->zoom = WIDTH;
	p->persp = 1;
	p->r = 255;
	p->v = 255;
	p->b = 255;
	p->degra = 0;
}

int		ft_build_mlx(t_af *p)
{
	ft_init(p);
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "fdf");
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	mlx_hook(p->win, 2, 2, ft_key_hook, p);
	mlx_mouse_hook(p->win, ft_mouse_hook, p);
	mlx_loop(p->mlx);
	return (0);
}
