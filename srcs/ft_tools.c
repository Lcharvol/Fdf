/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 01:07:06 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/26 01:07:09 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void				ft_degra2(t_af *af, int q)
{
	if (af->degra == 0)
		return ;
	else if (af->degra == 1)
		af->b = q;
	else if (af->degra == 2)
		af->r = q;
	else if (af->degra == 3)
		af->v = q;
}

void				ft_exit_error(void)
{
	ft_putstr("Invalid map\n");
	exit(1);
}

void				ft_print_info3(t_af *p, char *str)
{
	if (p->degra > 0)
	{
		str = "Degrade sur le ";
		mlx_string_put(p->mlx, p->win, 40, 190, 0x0FFFFFF, str);
		if (p->degra == 1)
		{
			str = "bleu";
			mlx_string_put(p->mlx, p->win, 200, 190, 0x0FFFFFF, str);
		}
		if (p->degra == 2)
		{
			str = "vert";
			mlx_string_put(p->mlx, p->win, 200, 190, 0x0FFFFFF, str);
		}
		if (p->degra == 3)
		{
			str = "rouge";
			mlx_string_put(p->mlx, p->win, 200, 190, 0x0FFFFFF, str);
		}
	}
	if (p->degra == 0)
	{
		str = "Pas de degrade";
		mlx_string_put(p->mlx, p->win, 40, 190, 0x0FFFFFF, str);
	}
}

void				ft_print_info2(t_af *p, char *str)
{
	str = "clic droit :";
	mlx_string_put(p->mlx, p->win, 40, 110, 0x0FFFFFF, str);
	str = " changer les couleurs:";
	mlx_string_put(p->mlx, p->win, 170, 110, 0x0FFFFFF, str);
	str = " v:";
	mlx_string_put(p->mlx, p->win, 385, 110, 0x0FFFFFF, str);
	str = ft_itoa(p->r);
	mlx_string_put(p->mlx, p->win, 420, 110, 0x0FFFFFF, str);
	str = " r:";
	mlx_string_put(p->mlx, p->win, 385, 130, 0x0FFFFFF, str);
	str = ft_itoa(p->v);
	mlx_string_put(p->mlx, p->win, 420, 130, 0x0FFFFFF, str);
	str = " b:";
	mlx_string_put(p->mlx, p->win, 385, 150, 0x0FFFFFF, str);
	str = ft_itoa(p->b);
	mlx_string_put(p->mlx, p->win, 420, 150, 0x0FFFFFF, str);
	str = "Opacite :";
	mlx_string_put(p->mlx, p->win, 40, 230, 0x0FFFFFF, str);
	str = ft_itoa(p->opacity);
	mlx_string_put(p->mlx, p->win, 420, 230, 0x0FFFFFF, str);
	ft_print_info3(p, str);
}

void				ft_print_info(t_af *p)
{
	char			*str;

	str = "Echap      :";
	mlx_string_put(p->mlx, p->win, 40, 10, 0x0FFFFFF, str);
	str = " quitter le programme";
	mlx_string_put(p->mlx, p->win, 170, 10, 0x0FFFFFF, str);
	str = "+ / -      :";
	mlx_string_put(p->mlx, p->win, 40, 30, 0x0FFFFFF, str);
	str = " zoom avant / arriere:";
	mlx_string_put(p->mlx, p->win, 170, 30, 0x0FFFFFF, str);
	str = ft_itoa(p->zoom);
	mlx_string_put(p->mlx, p->win, 420, 30, 0x0FFFFFF, str);
	str = "molette    :";
	mlx_string_put(p->mlx, p->win, 40, 70, 0x0FFFFFF, str);
	str = " modifier l'altitude:";
	mlx_string_put(p->mlx, p->win, 170, 70, 0x0FFFFFF, str);
	str = ft_itoa(p->deep);
	mlx_string_put(p->mlx, p->win, 420, 70, 0x0FFFFFF, str);
	str = "Delet:        reinitaliser la map";
	mlx_string_put(p->mlx, p->win, 40, 270, 0x0FFFFFF, str);
	ft_print_info2(p, str);
}
