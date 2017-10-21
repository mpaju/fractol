/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:49:59 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/21 14:45:10 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <fcntl.h>

# define WINX 1200
# define WINY 1200
# define ABS(x) x >= 0 ? x : -x

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				zoom;
	int				xcenter;
	int				ycenter;
	int				xmin;
	int				xmax;
	int				ymin;
	int				ymax;
	int				width;
	int				heigth;
	int				nb;
	char			*map;
}					t_env;

#endif
