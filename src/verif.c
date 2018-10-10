/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalmier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:39:18 by cpalmier          #+#    #+#             */
/*   Updated: 2018/08/07 15:56:02 by cpalmier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	verif(char *av, t_env *env)
{
	if (ft_strcmp(av, "Mandelbrot") == 0 || ft_strcmp(av, "mandelbrot") == 0)
	{
		env->mode = 1;
		return (1);
	}
	else if (ft_strcmp(av, "Julia") == 0 || ft_strcmp(av, "julia") == 0)
	{
		env->mode = 2;
		return (1);
	}
	else if (ft_strcmp(av, "Burning ship") == 0
			|| ft_strcmp(av, "burning ship") == 0)
	{
		env->mode = 3;
		return (1);
	}
	return (0);
}
