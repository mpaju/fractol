#include "fractol.h"

int	expose_test_hook(t_env *e)
{
	static int	c = -1;

	c++;
	printf("expose: %d\n", c);
	redraw(e);
	return(c);
}

int	mouse_mvmnt_hook(int x, int y, t_env *e)
{
	// printf("mouse pos x: %d, y: %d\n", x, y);
	if (!e->pause)
	{
		e->mousex = x;
		e->mousey = y;
		redraw(e);
	}
	return (0);
}

int	mouse_click_hook(int btn, int x, int y, t_env *e)
{
	printf("click pos x: %d, y: %d, btn: %d\n", x, y, btn);
	if (btn == 1 || btn == 4)
	{
		e->zoom *= 1.2;
		e->posx = e->posx + ((x / 5) / e->zoom);
		e->posy = e->posy + ((y / 5) / e->zoom);
		redraw(e);
	}
	if (btn == 2 || btn == 5)
	{
		e->zoom /= 1.2;
		e->posx = e->posx - ((x / (5 * 1.2)) / e->zoom);
		e->posy = e->posy - ((y / (5 * 1.2)) / e->zoom);
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
	if (key == 49)
		e->pause = (e->pause) ? 0 : 1;
	return (0);
}

void	catch_hooks(t_env *e)
{
	mlx_expose_hook(e->win, expose_test_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_click_hook, e);
	mlx_hook(e->win, 6, 0, mouse_mvmnt_hook, e);
}