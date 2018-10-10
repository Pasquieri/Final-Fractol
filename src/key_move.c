/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 17:57:12 by cpalmier          #+#    #+#             */
/*   Updated: 2018/08/07 17:02:41 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	key_move(int key, t_env *env)
{
	if (key == 124)
		env->x_min -= 50 / env->zoom;
	else if (key == 123)
		env->x_min += 50 / env->zoom;
	else if (key == 125)
		env->y_min -= 50 / env->zoom;
	else if (key == 126)
		env->y_min += 50 / env->zoom;
}
