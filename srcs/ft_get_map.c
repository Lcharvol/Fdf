/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 01:13:20 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/26 00:42:10 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int					ft_count_size(int fd)
{
	char			*line;
	int				count;
	int				spaces;
	int				tmp;
	int				i;

	tmp = 0;
	count = 0;
	while (ft_get_next_line(fd, &line) != 0)
	{
		spaces = 0;
		i = 0;
		while (line[i] && line[0] != '\0')
		{
			if (((line[i] >= 48 && line[i] <= 57) || (line[i] >= 65 && line[i]
				<= 90) || (line[i] >= 97 && line[i] <= 122)) &&
				(line[i + 1] == ' ' || line[i + 1] == '\0'))
				spaces++;
			i++;
		}
		count++;
		ft_count_size2(tmp, spaces);
		tmp = spaces;
	}
	return (count);
}

void				ft_get_map(struct s_map *map)
{
	int				i;
	int				fd;
	char			*line;

	i = 0;
	map->y = 0;
	fd = open(map->argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Invalid argument\n");
		exit(1);
	}
	map->y = ft_count_size(fd);
	close(fd);
	fd = open(map->argv[1], O_RDONLY);
	map->map = (char **)malloc(sizeof(char *) * map->y + 1);
	while ((ft_get_next_line(fd, &line)) != 0)
		if (line[0] != '\0')
			map->map[i++] = line;
		else
			map->y--;
	close(fd);
}

static	t_point		*ft_new_coord(int x, int y, int z, t_map *map)
{
	t_point			*point;

	if (!(point = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	point->size_x = (map->x);
	point->size_y = (map->y);
	point->z = z;
	point->x = x - point->size_x / 2;
	point->y = y - map->y / 2;
	return (point);
}

void				ft_stock_coord(int i, int i2, t_point ***point, t_map *map)
{
	while (i2 < map->x)
	{
		if (map->tmp[i2] && map->tmp[i2][0] != '\n')
			point[i][i2] = ft_new_coord(i2, i, ft_atoi(map->tmp[i2]), map);
		i2++;
	}
	free(map->tmp);
}

t_point				***ft_get_coord(struct s_map *map)
{
	int				i;
	int				i2;
	t_point			***point;

	i = 0;
	ft_get_map(map);
	if (!(point = (t_point ***)malloc(sizeof(t_point **) * map->y + 1)))
		return (NULL);
	while (i < map->y)
	{
		map->tmp = ft_strsplit(map->map[i], ' ');
		map->x = 0;
		while (map->tmp[map->x])
			map->x++;
		i2 = 0;
		if (!(point[i] = (t_point **)malloc(sizeof(t_point *) * (map->x + 1))))
			return (NULL);
		ft_stock_coord(i, i2, point, map);
		i++;
	}
	map->tmp = NULL;
	return (point);
}
