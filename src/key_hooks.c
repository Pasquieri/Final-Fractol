/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:15:06 by cpalmier          #+#    #+#             */
/*   Updated: 2018/07/03 17:12:59 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	key_zoom(int key, t_env *env)
{
	if (key == 69)
	{
		env->zoom *= 1.1;
		env->it_max += 1;
	}
	else if (key == 78)
	{
		env->zoom /= 1.1;
		if (env->it_max > 25)
			env->it_max -= 1;
	}
	else if (key == 24)
		env->it_max += 1;
	else if (key == 27)
	{
		if (env->it_max > 1)
			env->it_max -= 1;
	}
}

static void	julia_key(int key, t_env *env)
{
	if (key == 18)
	{
		env->c_r = 0.285;
		env->c_i = -0.013;
	}
	else if (key == 19)
	{
		env->c_r = -0.129;
		env->c_i = -0.768;
	}
	else if (key == 20)
	{
		env->c_r = -0.823;
		env->c_i = -0.134;
	}
	else if (key == 21)
	{
		env->c_r = -0.255;
		env->c_i = 0.756;
	}
	else if (key == 23)
	{
		env->c_r = 0.371;
		env->c_i = -0.1;
	}
}

static void	key_mode(int key, t_env *env)
{
	if (key == 83)
		env->mode = 1;
	else if (key == 84)
		env->mode = 2;
	else if (key == 85)
		env->mode = 3;
	init_env(env);
	env->zoom = 300;
}

void		key_hooks(int key, t_env *env)
{
	if (key == 69 || key == 78 || key == 24 || key == 27)
		key_zoom(key, env);
	else if (key >= 123 && key <= 126)
		key_move(key, env);
	else if (key >= 83 && key <= 85)
		key_mode(key, env);
	else if (key == 82 || key == 29)
	{
		init_color(env);
		init_env(env);
		env->zoom = 300;
	}
	else if (key >= 18 && key <= 23 && env->mode == 2)
	{
		init_env(env);
		julia_key(key, env);
	}
	else if (key == 3 || key == 5 || key == 9 || key == 11 ||
			key == 14 || key == 15)
		key_color(key, env);
	else if (key == 86)
		palette_color(key, env);
}
