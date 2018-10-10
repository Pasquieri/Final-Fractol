/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:10:11 by cpalmier          #+#    #+#             */
/*   Updated: 2018/08/07 12:32:44 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../Minilibx/mlx.h"
# include <math.h>

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_str;
	int		bpp;
	int		s_l;
	int		end;
	int		mode;
	int		space;
	double	z_r;
	double	z_i;
	double	c_r;
	double	c_i;
	double	tmp;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	zoom;
	double	img_x;
	double	img_y;
	int		it_max;
	int		it;
	int		color;
	int		palette;
	int		r;
	int		g;
	int		b;
}				t_env;

void			init_env(t_env *env);
void			init_color(t_env *env);
void			create_img(t_env *env);
void			fill_img(t_env *env);
void			put_pxl_img(t_env *env, int x, int y, int it);
void			put_pxl_img_color(t_env *env, int x, int y, int it);
void			palette_color(int key, t_env *env);
void			mandelbrot(t_env *env, void (*f)(t_env *, int, int, int));
void			julia(t_env *env, void (*f)(t_env *, int, int, int));
void			burning_ship(t_env *env, void (*f)(t_env *, int, int, int));
void			key_hooks(int key, t_env *env);
void			key_color(int key, t_env *env);
void			key_move(int key, t_env *env);
void			consigne(t_env *env);
int				verif(char *av, t_env *env);

#endif
