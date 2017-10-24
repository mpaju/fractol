#include "fractol.h"

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
	y0 = 4.0 * y0 / e->height - 2.0;
	while (x * x + y * y <= 4 && iteration < MAX_ITER)
	{
		xtmp = x * x - y * y + x0;
		y = 2 * x * y + y0;
		x = xtmp;
		iteration++;
	}
	return (iteration);
}

int julia(t_env *e, float x, float y)
{
	float	re;
	float	im;
	int iteration;
	float xtmp;

	iteration = 0;
	re = 4.0 * e->mousex / e->width - 2.0;
	im = 4.0 * e->mousey / e->height - 2.0;
	x = 4.0 * x / e->width - 2.0;
	y = 4.0 * y / e->width - 2.0;
	while (x * x + y * y <= 4 && iteration < MAX_ITER)
	{
		xtmp = x * x - y * y + re;
		y = 2 * x * y + im;
		x = xtmp;
		iteration++;
	}
	return (iteration);
}

int	burningship(t_env *e, float x0, float y0)
{
	float	x;
	float	y;
	int iteration;
	float xtmp;

	iteration = 0;
	x = 0;
	y = 0;
	x0 = 4.0 * x0 / e->width - 2.0;
	y0 = 4.0 * y0 / e->height - 2.0;
	while (x * x + y * y + x0 < 4 && iteration < MAX_ITER)
	{
		xtmp = x * x - y * y + x0;
		y = fabs(2 * x * y) + y0;
		x = xtmp;
		iteration++;
	}
	return (iteration);
}
