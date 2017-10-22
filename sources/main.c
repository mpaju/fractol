#include "fractol.h"

static void	check_args(int ac, char **av)
{
	if (ac != 2 || (!ft_strequ(av[1], "mandelbrot") && \
		!ft_strequ(av[1], "julia") && !ft_strequ(av[1], "...")))
	{
		ft_putendl_fd("Usage: ./fractol [mandelbrot | julia | ...]", 2);
		exit(1);
	}
}

int	expose_test_hook(t_env *e)
{
	static int	c = -1;

	c++;
	printf("c: %d\n", c);
	return(c);
}

int			main(int ac, char **av)
{
	t_env	*e;

	check_args(ac, av);
	e = (t_env *)ft_memalloc(sizeof(t_env));
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WINX, WINY, "hi");
	e->img = mlx_new_image(e->mlx, WINY, WINX);
	e->width = WINX;
	e->heigth = WINY;
	e->pixel = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	draw_smth(e);
	mlx_expose_hook(e->win, expose_test_hook, e);
	mlx_loop(e->mlx);
	return 0;
}