/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 06:29:55 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/26 00:00:34 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				ft_reset(t_af *af)
{
	af->deep = 0;
	af->tight = 0;
	af->tight2 = 0;
	af->zoom = WIDTH;
	af->persp = 1;
	af->r = 255;
	af->v = 255;
	af->b = 255;
	af->opacity = 0;
	af->degra = 0;
}

void				ft_count_size2(int tmp, int spaces)
{
	if (tmp != 0 && (tmp != spaces))
		ft_exit_error();
}

void				ft_get_map_hight(t_af *af)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i < af->point[0][0]->size_y)
	{
		j = 0;
		while (j < af->point[i][0]->size_x)
		{
			if (af->point[i][j]->z > af->max_hight)
				af->max_hight = af->point[i][j]->z;
			if (af->point[i][j]->z < af->min_hight)
				af->min_hight = af->point[i][j]->z;
			j++;
		}
		i++;
	}
}

int					main(int argc, char **argv)
{
	t_map			*map;
	t_af			*af;

	if (argc != 2)
	{
		ft_putstr("Invalide argument\n");
		return (0);
	}
	af = (t_af *)malloc(sizeof(t_af));
	map = (t_map *)malloc(sizeof(t_map));
	map->argv = argv;
	af->point = ft_get_coord(map);
	ft_get_map_hight(af);
	ft_build_mlx(af);
	free(map);
	free(af->point);
	free(af);
	return (0);
}
