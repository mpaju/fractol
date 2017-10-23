#include "fractol.h"

int	mandelbrot(t_env *e, float x0, float y0)
{
	float	x;
	float	y;
	int iteration;
	float xtmp;

	iteration = 0;
	// x0 = x0 / e->zoom + e->posx;
	// y0 = x0 / e->zoom + e->posy;
	x = 0;
	y = 0;
	x0 = 4.0 * x0 / e->width - 2.0;
	y0 = 4.0 * y0 / e->height - 2.0;
	// x0 = 4.0 * x0 / (e->width /*/ e->zoom*/) - 2.0 + (e->posx / e->width);
	// y0 = 4.0 * y0 / (e->height /*/ e->zoom*/) - 2.0 + (e->posy / e->height);
	while (x * x + y * y <= 4 && iteration < MAX_ITER)
	{
		xtmp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = xtmp;
		iteration++;
	}
	return (iteration);
}

int julia(t_env *e, float x0, float y0)
{
	return (0);
}

// void	draw_fractol(t_env *e)
// {
// 	int x;
// 	int y;
// 	int i;

// 	x = 0;
// 	y = 0;
// 	while (y < e->height)
// 	{
// 		while (x < e->width)
// 		{
// 			i = mandelbrot(e, (float)x + e->posx, (float)y + e->posy);
// 			if (i < MAX_ITER)
// 				put_pixel(e, x, y, e->colors[i]);
// 			x++;
// 		}
// 		y++;
// 		x = 0;
// 	}
// }

// void draw_smth(t_env *e)
// {	
// 	draw_mandel(e);
// 	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
// }
