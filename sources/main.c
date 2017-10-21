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

int			main(int ac, char **av)
{
	t_env	*e;

	check_args(ac, av);
	mlx_hook();
	return 0;
}