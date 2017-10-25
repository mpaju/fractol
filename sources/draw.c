/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:49:33 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/25 18:22:01 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_pixel(t_env *e, int x, int y, int color)
{
	int i;

	if (x >= 0 && y >= 0 && x < e->width && y < e->height)
	{
		i = (x * (e->bpp / 8)) + (y * e->size_line);
		e->pixel[i] = (char)color;
		e->pixel[++i] = (char)(color >> 8);
		e->pixel[++i] = (char)(color >> 16);
	}
}

static int	get_color(t_env *e)
{
	int	color;
	int r;
	int g;
	int	b;

	color = 0;
	r = sin(e->freq * e->maaagic + e->phase) * e->huewidth + e->huecenter;
	g = sin(e->freq * e->maaagic + e->phase + 2) * e->huewidth + e->huecenter;
	b = sin(e->freq * e->maaagic + e->phase + 4) * e->huewidth + e->huecenter;
	color = r << 16 | g << 8 | b;
	return (color);
}

void		draw_img(t_env *e)
{
	int	x;
	int	y;
	int i;

	x = 0;
	y = 0;
	while (y < e->height)
	{
		while (x < e->width)
		{
			i = e->fractol(e, x / e->zoom + e->posx, y / e->zoom + e->posy);
			if (i < e->max_iter)
			{
				put_pixel(e, x, y, get_color(e));
			}
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

static void	reset_img(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, e->width, e->height);
	e->pixel = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
}

void		redraw(t_env *e)
{
	reset_img(e);
	draw_img(e);
}
