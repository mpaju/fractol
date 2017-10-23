#include "fractol.h"

int	expose_test_hook(t_env *e)
{
	static int	c = -1;

	c++;
	printf("expose: %d\n", c);
	return(c);
}

int	mouse_mvmnt_hook(int x, int y, t_env *e)
{
	// printf("mouse pos x: %d, y: %d\n", x, y);
	return (0);
}

int	mouse_click_hook(int btn, int x, int y, t_env *e)
{
	printf("click pos x: %d, y: %d, btn: %d\n", x, y, btn);
	if (btn == 1)
	{
		// e->posx = (x / e->zoom + e->posx) - ((e->zoom * 1.2) / 2);
		// e->posx += ((e->zoom * 1.2) / 2) - (x / (e->zoom * 1.2));
		// e->posy = (y / e->zoom + e->posy) - ((e->zoom * 1.2) / 2);
		// e->posy += ((e->zoom * 1.2) / 2) - (y / (e->zoom * 1.2));
		// e->posx = e->posx + x - e->width / e->zoom;
		// e->posy = e->posy + y - e->height / e->zoom;
		// e->zoom *= 1.2;
		// e->posx = (x - e->width / 2) / e->zoom / 1.5;
		// e->posy = (y - e->height / 2) / e->zoom / 1.5;
		// e->posy = y / 5 * 1.2;
		// e->posx = e->posx + x / e->zoom;
		// e->posy = e->posy + y / e->zoom;
		e->zoom *= 1.2;
		e->posx = e->posx + ((x / 5) / e->zoom);
		e->posy = e->posy + ((y / 5) / e->zoom);
		// e->posx = x / 1.5 + (e->posx - e->width / e->zoom);
		// e->posy = y / 1.5 + (e->posy - e->height / e->zoom);
		redraw(e);
	}

	// data->x2 = x;
	// data->y2 = y;
	// data->x1 = (x / data->zoom + data->x1) - ((data->zoom * 1.3) / 2);
	// data->x1 += ((data->zoom * 1.3) / 2) - (x / (data->zoom * 1.3));
	// data->y1 = (y / data->zoom + data->y1) - ((data->zoom * 1.3) / 2);
	// data->y1 += ((data->zoom * 1.3) / 2) - (y / (data->zoom * 1.3));
	// data->zoom *= 1.3;
	// data->it_max++;
		// x -= v->width / 2;
		// y -= v->height / 2;
		// v->zoom = (v->zoom + 1) * 1.1;
		// v->x_shift += x / v->zoom / 1.5;
		// v->y_shift += y / v->zoom / 1.5;
	if (btn == 5)
	{
		e->zoom /= 1.2;
		redraw(e);
	}
	return (0);
}

int	key_hook(int key, t_env *e)
{
	printf("key: %d\n", key);
	if (key == 53)
		exit(0);
	if (key == 123)
	{
		e->posx += 100;
		redraw(e);
	}
	return (0);
}

void	catch_hooks(t_env *e)
{
	mlx_expose_hook(e->win, expose_test_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_click_hook, e);
	mlx_hook(e->win, 6, 0, mouse_mvmnt_hook, e);
}