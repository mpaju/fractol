#include "fractol.h"

void	testfunc(void)
{
	return ;
}
void	testfunc2(void)
{
	return ;
}


void	put_pixel(t_env *e, int x, int y, int color)
{
	int i;

	if (x == 200 && y == 200)
		testfunc();
	if (x >= 0 && y >= 0 && x < e->width && y < e->heigth)
	{
		i = (x * (e->bpp / 8)) + (y * e->size_line);
		e->pixel[i] = color;
		e->pixel[++i] = color >> 8;
		e->pixel[++i] = color >> 16;
	}
}

int	mandelbrot(t_env *e, float x0, float y0)
{
	float	x;
	float	y;
	int iteration;
	float xtmp;

	iteration = 0;
	x = 0;
	y = 0;
	x0 = 4.0 * x0 / e->width - 2.0;
	y0 = 4.0 * y0 / e->heigth - 2.0;
	while (x * x + y * y < 4 && iteration < MAX_ITER)
	{
		xtmp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = xtmp;
		iteration++;
	}
	return (iteration);
}

void	draw_mandel(t_env *e)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	while (y < e->heigth)
	{
		while (x < e->width)
		{
			i = mandelbrot(e, (float)x, (float)y);
			if (i < MAX_ITER)
				put_pixel(e, x, y, e->colors[i]);
				// e->pixel[(x * (e->bpp / 8)) + (y * e->size_line)] = 1;
			// else
			// 	put_pixel(e, x, y, 0xFFFFFF);
				// e->pixel[(x * (e->bpp / 8)) + (y * e->size_line)] = 254;
			x++;
		}
		y++;
		x = 0;
	}
	testfunc2();
}

void draw_smth(t_env *e)
{	
	create_color_table(e);
	draw_mandel(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
