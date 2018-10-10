/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:13:57 by cpalmier          #+#    #+#             */
/*   Updated: 2018/08/07 12:27:43 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	deal_key(int key, t_env *env)
{
	if (key == 53)
		exit(0);
	if (key == 69 || key == 78 || (key >= 123 && key <= 126)
			|| (key >= 82 && key <= 86) || key == 15 || key == 14 || key == 3
			|| key == 5 || key == 11 || key == 9 || (key >= 18 && key <= 21)
			|| key == 23 || key == 24 || key == 27 || key == 29)
	{
		mlx_clear_window(env->mlx, env->win);
		env->img = mlx_new_image(env->mlx, 1500, 1100);
		env->img_str = mlx_get_data_addr(env->img, &env->bpp, &env->s_l,
				&env->end);
		key_hooks(key, env);
		fill_img(env);
		consigne(env);
	}
	if (key == 49 && env->space == 1)
		env->space = 0;
	else if (key == 49 && env->space == 0)
		env->space = 1;
	return (0);
}

static int	red_cross(int key)
{
	(void)key;
	exit(0);
	return (0);
}

static int	motion_notify(int x, int y, t_env *env)
{
	float	a;
	float	b;

	a = (float)x;
	b = (float)y;
	if (env->mode == 2 && env->space == 1)
	{
		mlx_clear_window(env->mlx, env->win);
		env->img = mlx_new_image(env->mlx, 1500, 1100);
		env->img_str = mlx_get_data_addr(env->img, &env->bpp, &env->s_l,
				&env->end);
		init_env(env);
		a = a - 750;
		b = b - 500;
		env->c_r = a / 650;
		env->c_i = -b / 500;
		fill_img(env);
		consigne(env);
	}
	return (0);
}

static int	button_press(int button, int x, int y, t_env *env)
{
	int	key;

	key = 0;
	if (button == 4 || button == 5)
	{
		if (button == 4)
			key = 78;
		else if (button == 5)
			key = 69;
		mlx_clear_window(env->mlx, env->win);
		env->img = mlx_new_image(env->mlx, 1500, 1100);
		env->img_str = mlx_get_data_addr(env->img, &env->bpp, &env->s_l,
				&env->end);
		key_hooks(key, env);
		fill_img(env);
		consigne(env);
	}
	(void)x;
	(void)y;
	return (0);
}

int			main(int ac, char **av)
{
	t_env	env;

	if (ac != 2 || (verif(av[1], &env) == 0))
	{
		ft_putstr("usage : ./fractol [fractale]\nfractales :\n");
		ft_putstr("\t--> Mandelbrot\n\t--> Julia\n\t--> Burning ship\n");
		exit(0);
	}
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 1500, 1100, "fract'ol");
	env.space = 1;
	env.palette = 0;
	env.zoom = 300;
	init_env(&env);
	init_color(&env);
	create_img(&env);
	consigne(&env);
	mlx_hook(env.win, 2, 3, deal_key, &env);
	mlx_hook(env.win, 4, 1L << 2, button_press, &env);
	mlx_hook(env.win, 17, 3, red_cross, &env);
	mlx_hook(env.win, 6, 1L << 13, motion_notify, &env);
	mlx_loop(env.mlx);
	return (0);
}
