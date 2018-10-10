/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 14:53:52 by cpalmier          #+#    #+#             */
/*   Updated: 2018/08/07 14:40:01 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	init_var(t_env *env, int x, int y)
{
	env->it = 1;
	env->c_r = x / env->zoom + env->x_min;
	env->c_i = y / env->zoom + env->y_min;
	env->z_r = fabs(env->c_r);
	env->z_i = fabs(env->c_i);
}

void		burning_ship(t_env *env, void (*f)(t_env *, int, int, int))
{
	int	x;
	int	y;

	x = -1;
	while (++x < 1500)
	{
		y = -1;
		while (++y < 1100)
		{
			init_var(env, x, y);
			while (((env->z_r * env->z_r + env->z_i * env->z_i) < 4)
					&& (env->it < env->it_max))
			{
				env->tmp = env->z_r;
				env->z_r = fabs(env->z_r) * fabs(env->z_r) - fabs(env->z_i)
					* fabs(env->z_i) + env->c_r;
				env->z_i = 2 * fabs(env->tmp) * fabs(env->z_i) + env->c_i;
				env->it++;
			}
			f(env, x, y, env->it);
		}
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
