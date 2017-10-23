#include "fractol.h"

static void	check_args(t_env *e, int ac, char **av)
{
	if (ac != 2 || (!ft_strequ(av[1], "1") && \
		!ft_strequ(av[1], "2") /*&& !ft_strequ(av[1], "3")*/))
	{
		ft_putendl_fd("Usage: ./fractol [fractol number]", 2);
		ft_putendl_fd("1 - Julia", 2);
		ft_putendl_fd("2 - Mandelbrot", 2);
		ft_putendl_fd("3 - idk what", 2);
		ft_putendl_fd("Examle: ./fractol 1", 2);
		exit(1);
	}
	if (ft_strequ(av[1], "1"))
		e->fractol = julia;
	else if (ft_strequ(av[1], "2"))
		e->fractol = mandelbrot;
	// else if (ft_strequ(av[1], "3"))
	// 	e->fractol = 
}

static void	init_picture(t_env *e)
{
	e->mlx = mlx_init();
	e->width = WINX;
	e->height = WINY;
	e->win = mlx_new_window(e->mlx, e->width, e->height, "hi");
	e->img = mlx_new_image(e->mlx, e->width, e->height);
	e->pixel = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	e->zoom = 1;
	e->posx = 0;
	e->posy = 0;
	create_color_table(e);
}

int			main(int ac, char **av)
{
	t_env	*e;

	e = (t_env *)ft_memalloc(sizeof(t_env));
	init_picture(e);
	check_args(e, ac, av);
	draw_img(e);
	catch_hooks(e);
	mlx_loop(e->mlx);
	return 0;
}