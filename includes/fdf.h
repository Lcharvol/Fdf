/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 03:39:19 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/27 02:47:32 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "math.h"
# include "../libft/libft.h"
# define WIDTH 2560
# define HEIGHT 1440
# define ECHAP	53
# define UP		126
# define DOWN	125
# define RIGHT	124
# define LEFT	123
# define ZOOM	69
# define DEZOOM	78

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				size_x;
	int				size_y;
}					t_point;

typedef struct		s_af
{
	int				s_line;
	void			*win;
	void			*mlx;
	void			*img;
	t_point			***point;
	int				deep;
	unsigned int	tight;
	unsigned int	tight2;
	int				zoom;
	int				persp;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	char			*ret;
	int				tmpz;
	int				tmpi;
	int				tmpj;
	int				couleur;
	int				r;
	int				v;
	int				b;
	int				min_hight;
	int				max_hight;
	int				degra;
	int				opacity;

}					t_af;

typedef struct		s_map
{
	char			**argv;
	char			**map;
	char			**tmp;
	int				x;
	int				y;
}					t_map;

int					ft_key_hook(int keycode, t_af *af);
int					ft_key_hook2(int keycode, t_af *af);
int					ft_key_hook3(int keycode, t_af *af);
int					ft_key_hook4(int keycode, t_af *af);
void				ft_degra2(t_af *af, int q);
void				ft_exit_error(void);
void				ft_print_info(t_af *p);
void				ft_print_info2(t_af *p, char *str);
void				ft_reset(t_af *af);
unsigned int		ft_color(t_af *af, int i2, int j);
void				ft_count_size2(int tmp, int spaces);
void				ft_exit_error();
static int			ft_loop_key_hook(t_af *af);
void				ft_reset(t_af *af);
void				ft_get_map(struct s_map *map);
t_point				***ft_get_coord(struct s_map *map);
int					ft_build_mlx(struct s_af *p);
int					ft_expose_hook(t_af *p);
void				ft_choose_persp(t_af *af, int i, int j);
void				ft_iso_persp(t_af *af, int i, int j);
void				ft_print_info(t_af *p);
unsigned int		ft_color(t_af *af, int i, int j);
int					ft_key_hook(int keycode, t_af *af);
int					ft_mouse_hook(int button, int x, int y, t_af *af);
int					ft_mlx_event(struct s_af *af);
void				ft_put_point(struct s_af *af);

#endif
