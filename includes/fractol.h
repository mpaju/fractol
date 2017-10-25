/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:49:59 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/25 18:22:16 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <fcntl.h>

# define MAX_ITER 64
# define WINX 1200
# define WINY 1200
# define ABS(x) x >= 0 ? x : -x

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*pixel;
	int			*colors;
	int			bpp;
	int			size_line;
	int			endian;
	char		*fractal_num;
	int			(*fractol)(struct s_env*, float x, float y);
	int			max_iter;
	int			width;
	int			height;
	int			pause;
	int			mousex;
	int			mousey;
	double		freq;
	double		phase;
	double		maaagic;
	int			huecenter;
	int			huewidth;
	double		zoom;
	double		posx;
	double		posy;
}				t_env;

int				burningship(t_env *e, float x0, float y0);
int				julia(t_env *e, float x0, float y0);
int				mandelbrot(t_env *e, float x0, float y0);
int				catch_hooks(t_env *e);
void			draw_img(t_env *e);
int				expose_hook(t_env *e);
int				key_hook(int key, t_env *e);
int				mouse_click_hook(int btn, int x, int y, t_env *e);
int				mouse_mvmnt_hook(int x, int y, t_env *e);
void			redraw(t_env *e);

#endif
