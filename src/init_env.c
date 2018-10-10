/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:27:23 by cpalmier          #+#    #+#             */
/*   Updated: 2018/07/03 17:19:14 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	init_mandelbrot(t_env *env)
{
	env->x_min = -2.3;
	env->x_max = 0.6;
	env->y_min = -1.5;
	env->y_max = 1.2;
	env->it_max = 50;
}

static void	init_julia(t_env *env)
{
	env->x_min = -2;
	env->x_max = 2;
	env->y_min = -1.6;
	env->y_max = 1.2;
	env->c_r = -0.8;
	env->c_i = -0.2;
	env->it_max = 80;
}

static void	init_burning_ship(t_env *env)
{
	env->x_min = -2.2;
	env->x_max = 1;
	env->y_min = -2;
	env->y_max = 1.2;
	env->it_max = 50;
}

void		init_env(t_env *env)
{
	if (env->mode == 1)
		init_mandelbrot(env);
	else if (env->mode == 2)
		init_julia(env);
	else if (env->mode == 3)
		init_burning_ship(env);
}
