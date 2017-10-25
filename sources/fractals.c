/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:49:47 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/25 18:14:51 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_env *e, float x0, float y0)
{
	float	x;
	float	y;
	int		iteration;
	float	xtmp;

	iteration = 0;
	x = 0;
	y = 0;
	x0 = 4.0 * x0 / e->width - 2.0;
	y0 = 4.0 * y0 / e->height - 2.0;
	while (x * x + y * y <= 4 && iteration < e->max_iter)
	{
		xtmp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = xtmp;
		iteration++;
	}
	e->maaagic = iteration + 1 - (log(2) / sqrt(x * x + y * y)) / log(2);
	return (iteration);
}

int	julia(t_env *e, float x, float y)
{
	float	re;
	float	im;
	int		iteration;
	float	xtmp;

	iteration = 0;
	re = 4.0 * e->mousex / e->width - 2.0;
	im = 4.0 * e->mousey / e->height - 2.0;
	x = 4.0 * x / e->width - 2.0;
	y = 4.0 * y / e->width - 2.0;
	while (x * x + y * y <= 4 && iteration < e->max_iter)
	{
		xtmp = x * x - y * y + re;
		y = 2 * x * y + im;
		x = xtmp;
		iteration++;
	}
	e->maaagic = iteration + 1 - (log(2) / sqrt(x * x + y * y)) / log(2);
	return (iteration);
}

int	burningship(t_env *e, float x0, float y0)
{
	float	x;
	float	y;
	int		iteration;
	float	xtmp;

	iteration = 0;
	x = 0;
	y = 0;
	x0 = 4.0 * x0 / e->width - 2.0;
	y0 = 4.0 * y0 / e->height - 2.0;
	while (x * x + y * y + x0 <= 4 && iteration < e->max_iter)
	{
		xtmp = x * x - y * y + x0;
		y = fabs(2 * x * y) + y0;
		x = xtmp;
		iteration++;
	}
	e->maaagic = iteration + 1 - (log(2) / sqrt(x * x + y * y)) / log(2);
	return (iteration);
}
