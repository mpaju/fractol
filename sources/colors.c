#include "fractol.h"

void	create_color_table(t_env *e)
{
	int num_colors;
	int i;

	i = 0;
	num_colors = MAX_ITER;
	e->colors = (int *)ft_memalloc(sizeof(int) * num_colors);
	while (i < num_colors)
	{
		e->colors[i] = (char)(255 / num_colors * i) % 256 << 16;
		e->colors[i] = (char)(255 / num_colors * i) % 256 << 8;
		e->colors[i] = (char)(255 / num_colors * i) % 256;
		// on seda % vaja v?
		// e->colors[i] = e->colors[i] << 8;
		i++;
	}
}