/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pxl_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 16:46:52 by cpalmier          #+#    #+#             */
/*   Updated: 2018/07/03 19:55:27 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	verif_valeur(int *r, int *g, int *b, t_env *env)
{
	if (*r > 255)
		*r = 255;
	if (*g > 255)
		*g = 255;
	if (*b > 255)
		*b = 255;
	if (env->it == env->it_max)
	{
		*r = 0;
		*g = 0;
		*b = 0;
	}
}

void		put_pxl_img(t_env *env, int x, int y, int it)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 4 * x + y * env->s_l;
	r = env->r + it * 255 / env->it_max;
	b = env->b + it * 255 / env->it_max;
	g = env->g + it * 255 / env->it_max;
	verif_valeur(&r, &g, &b, env);
	env->img_str[i] = (char)b;
	env->img_str[i + 1] = (char)g;
	env->img_str[i + 2] = (char)r;
}

static int	condition(int *g, int *b, int *r, t_env *env)
{
	if (env->it == 1)
		*r = env->g + env->it * 255 / env->it_max + 70;
	else if (env->it == 2)
		*b = env->b + env->it * 255 / env->it_max + 50;
	else if (env->it < (env->it_max / 15))
		*r = env->g + env->it * 255 / env->it_max + 50;
	else if (env->it < (env->it_max / 12))
		*g = env->b + env->it * 255 / env->it_max + 40;
	else if (env->it < (env->it_max / 7))
		*b = env->g + env->it * 255 / env->it_max + 21;
	else if (env->it < (env->it_max / 5))
		*r = env->b + env->it * 255 / env->it_max + 40;
	else if (env->it < (env->it_max / 4))
		*g = env->g + env->it * 255 / env->it_max + 21;
	else if (env->it < (env->it_max / 3))
		*b = env->b + env->it * 255 / env->it_max;
	else if (env->it < (env->it_max / 2))
		*r = env->g + env->it * 255 / env->it_max;
	else if (env->it != env->it_max)
	{
		*r = env->r + env->it * 255 / env->it_max - 20;
		*b = env->b + env->it * 255 / env->it_max - 20;
		*g = env->g + env->it * 255 / env->it_max - 20;
	}
	return (0);
}

void		put_pxl_img_color(t_env *env, int x, int y, int it)
{
	int	r;
	int	g;
	int	b;

	(void)it;
	r = 0;
	g = 0;
	b = 0;
	condition(&g, &b, &r, env);
	verif_valeur(&r, &g, &b, env);
	env->img_str[4 * x + y * env->s_l] = (char)b;
	env->img_str[4 * x + y * env->s_l + 1] = (char)g;
	env->img_str[4 * x + y * env->s_l + 2] = (char)r;
}
