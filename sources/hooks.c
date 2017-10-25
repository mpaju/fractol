/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:49:41 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/25 18:14:39 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			expose_hook(t_env *e)
{
	redraw(e);
	return (0);
}

int			mouse_mvmnt_hook(int x, int y, t_env *e)
{
	if (!e->pause)
	{
		e->mousex = x;
		e->mousey = y;
	}
	redraw(e);
	return (0);
}

int			mouse_click_hook(int btn, int x, int y, t_env *e)
{
	if (btn == 1 || btn == 4)
	{
		e->zoom *= 1.2;
		e->posx = e->posx + ((x / 5) / e->zoom);
		e->posy = e->posy + ((y / 5) / e->zoom);
	}
	else if (btn == 2 || btn == 5)
	{
		e->zoom /= 1.2;
		e->posx = e->posx - ((x / (5 * 1.2)) / e->zoom);
		e->posy = e->posy - ((y / (5 * 1.2)) / e->zoom);
	}
	redraw(e);
	return (0);
}

static int	key_hook2(int key, t_env *e)
{
	if (key == 53)
		exit(0);
	else if (key == 0)
		e->freq *= 1.1;
	else if (key == 1)
		e->freq /= 1.1;
	else if (key == 2)
		e->phase += 0.1;
	else if (key == 3)
		e->phase -= 0.1;
	else if (key == 6)
		e->huecenter += 5;
	else if (key == 7)
		e->huecenter -= 5;
	else if (key == 8)
		e->huewidth += 5;
	else if (key == 9)
		e->huewidth -= 5;
	else if (key == 12)
		e->max_iter++;
	else if (key == 13)
		e->max_iter--;
	return (0);
}

int			key_hook(int key, t_env *e)
{
	if (key == 49)
	{
		e->pause = (e->pause) ? 0 : 1;
		return (0);
	}
	else if (key == 123)
		e->posx -= 10 / e->zoom;
	else if (key == 124)
		e->posx += 10 / e->zoom;
	else if (key == 126)
		e->posy -= 10 / e->zoom;
	else if (key == 125)
		e->posy += 10 / e->zoom;
	else if (key == 0)
		e->freq *= 1.1;
	else if (key == 1)
		e->freq /= 1.1;
	else if (key == 2)
		e->phase += 0.1;
	else if (key == 3)
		e->phase -= 0.1;
	else
		key_hook2(key, e);
	redraw(e);
	return (0);
}
