/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:17:30 by cpalmier          #+#    #+#             */
/*   Updated: 2018/07/03 17:15:03 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	init_color(t_env *env)
{
	env->color = 0xFFFFFF;
	env->r = 0;
	env->b = 0;
	env->g = 0;
}

void	key_color(int key, t_env *env)
{
	if (key == 15 && env->r < 255)
		env->r += 5;
	else if (key == 14 && env->r > 0)
		env->r -= 5;
	else if (key == 5 && env->g < 255)
		env->g += 5;
	else if (key == 3 && env->g > 0)
		env->g -= 5;
	else if (key == 11 && env->b < 255)
		env->b += 5;
	else if (key == 9 && env->b > 0)
		env->b -= 5;
}

void	palette_color(int key, t_env *env)
{
	if (env->palette == 0)
		env->palette = 1;
	else if (env->palette == 1)
		env->palette = 0;
	(void)key;
}
