/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:02:22 by cpalmier          #+#    #+#             */
/*   Updated: 2018/07/03 17:31:01 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fill_img(t_env *env)
{
	if (env->mode == 1)
	{
		if (env->palette == 0)
			mandelbrot(env, put_pxl_img);
		else
			mandelbrot(env, put_pxl_img_color);
	}
	else if (env->mode == 2)
	{
		if (env->palette == 0)
			julia(env, put_pxl_img);
		else
			julia(env, put_pxl_img_color);
	}
	else if (env->mode == 3)
	{
		if (env->palette == 0)
			burning_ship(env, put_pxl_img);
		else
			burning_ship(env, put_pxl_img_color);
	}
}

void	create_img(t_env *env)
{
	env->img = mlx_new_image(env->mlx, 1500, 1100);
	env->img_str = mlx_get_data_addr(env->img, &env->bpp, &env->s_l, &env->end);
	fill_img(env);
	mlx_destroy_image(env->mlx, env->img);
}
