/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:49:59 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/23 21:29:45 by mpaju            ###   ########.fr       */
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

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pixel;
	int				*colors;
	int				bpp;
	int				size_line;
	int				endian;
	int				(*fractol)(struct s_env*, float x, float y);
	int				width;
	int				height;
	double			zoom;
	double			posx;
	double			posy;
}					t_env;

void	catch_hooks(t_env *e);
void	create_color_table(t_env *e);
void 	draw_img(t_env *e);
int		julia(t_env *e, float x0, float y0);
int		mandelbrot(t_env *e, float x0, float y0);
void	put_pixel(t_env *e, int x, int y, int color);
int		test_hook(t_env *e);
void	redraw(t_env *e);

#endif
