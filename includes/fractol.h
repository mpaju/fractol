/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:49:59 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/22 21:21:09 by mpaju            ###   ########.fr       */
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
	int				zoom;
	int				width;
	int				heigth;
}					t_env;

void	create_color_table(t_env *e);
int	test_hook(t_env *e);
void draw_smth(t_env *e);

#endif
