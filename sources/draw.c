#include "fractol.h"

void	put_pixel(t_env *e, int x, int y, int color)
{
	int i;

	if (x >= 0 && y >= 0 && x < e->width && y < e->height)
	{
		i = (x * (e->bpp / 8)) + (y * e->size_line);
		e->pixel[i] = color;
		// e->pixel[++i] = color >> 8;
		// e->pixel[++i] = color >> 16;
	}
}

void	draw_img(t_env *e)
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
			i = e->fractol(e, (float)x / e->zoom + e->posx, (float)y / e->zoom + e->posy);
			// i = e->fractol(e, (float)(x + e->posx) / e->zoom, (float)(y + e->posy) /e->zoom);
			// i = e->fractol(e, (float)(x + e->posx) / e->zoom, (float)(y + e->posy) / e->zoom);
			// i = e->fractol(e, (float)(x + e->posx) / e->zoom, (float)(y + e->posy) / e->zoom);
			if (i < MAX_ITER)
				put_pixel(e, x, y, e->colors[i]);
			x++;
		}
		y++;
		x = 0;
	}
	printf("posx: %f, posy: %f, e->zoom: %f\n", e->posx, e->posy, e->zoom);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

void	reset_img(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, e->width, e->height);
	e->pixel = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	printf("new img addr: %p\n", e->img);
}

void	redraw(t_env *e)
{
	int x;
	int y;
	int i;

	reset_img(e);
	draw_img(e);
}