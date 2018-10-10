/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consigne.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:16:43 by cpalmier          #+#    #+#             */
/*   Updated: 2018/08/07 16:42:09 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	consigne_mandelbrot(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 990, 975, env->color,
			"4 : autres couleurs");
	mlx_string_put(env->mlx, env->win, 1140, 700, env->color,
			"MANDELBROT");
}

static void	consigne_julia(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 1140, 700, env->color,
			"JULIA");
	mlx_string_put(env->mlx, env->win, 990, 975, env->color,
			"4 : autres couleurs");
	mlx_string_put(env->mlx, env->win, 990, 1025, env->color,
			"SPACE : arrete la variation du param de Julia");
	mlx_string_put(env->mlx, env->win, 990, 1050, env->color,
			"1 - 5 (au dessus clavier) : differentes formes");
	mlx_string_put(env->mlx, env->win, 990, 1075, env->color,
			"de Julia");
}

static void	consigne_burning_ship(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 990, 975, env->color,
			"4 : autres couleurs");
	mlx_string_put(env->mlx, env->win, 1140, 700, env->color,
			"BURNING SHIP");
}

void		consigne(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 990, 750, env->color,
			"appuyer sur ESC pour fermer la fenetre");
	mlx_string_put(env->mlx, env->win, 990, 775, env->color,
			"utiliser les fleches pour deplacer");
	mlx_string_put(env->mlx, env->win, 990, 800, env->color,
			"1 - 3 : changer de Fractale");
	mlx_string_put(env->mlx, env->win, 990, 825, env->color,
			"+ / - ou molette : zoomer / dezoomer");
	mlx_string_put(env->mlx, env->win, 990, 850, env->color,
			"+ / - (au dessus clavier) : varie nb d'iterations");
	mlx_string_put(env->mlx, env->win, 990, 900, env->color,
			"Pour modifier les couleurs : ");
	mlx_string_put(env->mlx, env->win, 990, 925, env->color,
			"R / G / B pour augmenter le rouge, vert, bleu");
	mlx_string_put(env->mlx, env->win, 990, 950, env->color,
			"E / F / V pour les diminuer respectivement (0-255)");
	mlx_string_put(env->mlx, env->win, 990, 1000, env->color,
			"0 : reinitialise la fenetre");
	if (env->mode == 1)
		consigne_mandelbrot(env);
	else if (env->mode == 2)
		consigne_julia(env);
	else if (env->mode == 3)
		consigne_burning_ship(env);
}
