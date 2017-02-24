/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_persp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:51:22 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/26 00:24:25 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_my_pixel_put(t_af *af, int i, int j, float q)
{
	int			k;

	ft_degra2(af, q);
	if ((i > 0 && j > 0 && i < WIDTH && j < HEIGHT))
	{
		af->ret[((i * 4 + (j * af->size_line)))] = af->b;
		af->ret[((i * 4 + (j * af->size_line))) + 1] = af->r;
		af->ret[((i * 4 + (j * af->size_line))) + 2] = af->v;
		af->ret[((i * 4 + (j * af->size_line))) + 3] = af->opacity;
	}
}

float			ft_degra(t_af *af, t_point *b, t_point *a, int i)
{
	float		ret;
	float		dif;
	float		alt;

	dif = (float)(i - a->x) / (float)(b->x - a->x);
	alt = (float)(a->z + ((b->z - a->z) * dif)) /
	(float)(af->max_hight - af->min_hight);
	ret = 255 * alt;
	return (ret);
}

void			ft_wire(t_af *af, t_point *b, t_point *a)
{
	int			i;
	int			j;

	if ((b->x - a->x) == 0)
		return ;
	i = a->x;
	j = ((b->y - a->y) * (i - a->x)) / (b->x - a->x) + a->y;
	while (i < b->x)
	{
		while (j <= ((b->y - a->y) * (i + 1 - a->x) / (b->x - a->x)) + a->y)
			ft_my_pixel_put(af, i, j++, ft_degra(af, b, a, i));
		while (j > ((b->y - a->y) * (i + 1 - a->x) / (b->x - a->x)) + a->y)
			ft_my_pixel_put(af, i, j--, ft_degra(af, b, a, i));
		i++;
	}
}

void			ft_iso_persp(t_af *af, int i, int j)
{
	int			x;
	int			y;
	t_point		***c;

	c = af->point;
	c[i][j]->x = (af->zoom * (i + j) / (c[i][j]->size_x +
				c[i][j]->size_y)) + af->tight2;
	c[i][j]->y = ((af->zoom * (c[i][j]->size_x + i - j) /
				(c[i][j]->size_x + c[i][j]->size_y) - (c[i][j]->z)
				* af->deep) + af->tight);
	c[i][j]->y = c[i][j]->y / 2;
	if (j > 0)
		ft_wire(af, c[i][j], c[i][j - 1]);
	if (i > 0)
		ft_wire(af, c[i][j], c[i - 1][j]);
}

void			ft_choose_persp(t_af *af, int i, int j)
{
	if (af->persp == 1)
		ft_iso_persp(af, i, j);
}
