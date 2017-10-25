/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:49:54 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/25 18:20:35 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	exit_fractol(void)
{
	exit(0);
}

static void	check_args(t_env *e, int ac, char **av)
{
	if (ac != 2 || (!ft_strequ(av[1], "1") && \
		!ft_strequ(av[1], "2") && !ft_strequ(av[1], "3")))
	{
		ft_putendl_fd("Usage: ./fractol [fractol number]", 2);
		ft_putendl_fd("1 - Julia", 2);
		ft_putendl_fd("2 - Mandelbrot", 2);
		ft_putendl_fd("3 - burningship", 2);
		ft_putendl_fd("Examle: ./fractol 1", 2);
		exit(1);
	}
	e->fractal_num = av[1];
	ft_putendl("~Welcome to the fractol machine~");
	ft_putendl("Controls: ");
	ft_putendl("a/s - change color frequency");
	ft_putendl("d/f - change color phase");
	ft_putendl("z/x/c/v - varies color hue");
	ft_putendl("q/w - change the number of iterations (default 64)");
	ft_putendl("Use your mousewheel or buttons to zoom in/out");
	ft_putendl("Press Esc to exit");
	ft_putendl("");
	ft_putendl("ENJOY!");
}

static void	init_picture(t_env *e)
{
	e->mlx = mlx_init();
	e->width = WINX;
	e->height = WINY;
	e->win = mlx_new_window(e->mlx, e->width, e->height, "Fractal machine");
	e->img = mlx_new_image(e->mlx, e->width, e->height);
	e->pixel = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	e->zoom = 1;
	e->posx = 0;
	e->posy = 0;
	e->freq = 0.1;
	e->phase = 100;
	e->max_iter = MAX_ITER;
	e->huecenter = 127;
	e->huewidth = 128;
	e->pause = 1;
	if (ft_strequ(e->fractal_num, "1"))
	{
		e->fractol = julia;
		e->pause = 0;
	}
	else if (ft_strequ(e->fractal_num, "2"))
		e->fractol = mandelbrot;
	else if (ft_strequ(e->fractal_num, "3"))
		e->fractol = burningship;
}

int			catch_hooks(t_env *e)
{
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_click_hook, e);
	mlx_hook(e->win, 6, 0, mouse_mvmnt_hook, e);
	mlx_hook(e->win, 17, 0, exit_fractol, 0);
	return (0);
}

int			main(int ac, char **av)
{
	t_env	*e;

	e = (t_env *)ft_memalloc(sizeof(t_env));
	check_args(e, ac, av);
	init_picture(e);
	draw_img(e);
	catch_hooks(e);
	mlx_loop(e->mlx);
	return (0);
}
