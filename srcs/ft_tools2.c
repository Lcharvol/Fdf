/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 02:08:11 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/27 02:08:12 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int					ft_key_hook2(int keycode, t_af *af)
{
	if (keycode == DEZOOM)
	{
		af->zoom -= 50;
		af->tight2 += 25;
		af->tight += 25;
	}
	if (keycode == 86)
	{
		if ((af->r -= 10) < 0)
			af->r = 0;
		else
			af->r -= 10;
	}
	if (keycode == 87)
	{
		if ((af->v -= 10) < 0)
			af->v = 0;
		else
			af->v -= 10;
	}
	if (keycode == 89)
		af->degra = 1;
	if (keycode == 91)
		af->degra = 2;
	return (ft_key_hook3(keycode, af));
}

int					ft_key_hook3(int keycode, t_af *af)
{
	if (keycode == 88)
	{
		if ((af->b -= 10) < 0)
			af->b = 0;
		else
			af->b -= 10;
	}
	if (keycode == 92)
		af->degra = 3;
	if (keycode == 83)
	{
		if ((af->r += 10) > 255)
			af->r = 255;
		else
			af->r += 10;
	}
	if (keycode == 84)
	{
		if ((af->v += 10) > 255)
			af->v = 255;
		else
			af->v += 10;
	}
	return (ft_key_hook4(keycode, af));
}
