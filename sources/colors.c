#include "fractol.h"

void	create_color_table(t_env *e)
{
	int num_colors;
	int i;
	int	r;
	int	g;
	int	b;
	float freq;

	i = 0;
	freq = 0.02;
	num_colors = MAX_ITER;
	e->colors = (int *)ft_memalloc(sizeof(int) * num_colors);
	while (i < num_colors)
	{
		r = sin(freq * i + 0.1) * 55 + 200;
		g = sin(freq * i + 0.2) * 55 + 200;
		b = sin(freq * i + 0.4) * 55 + 200;
		e->colors[i] = r << 16 | g << 8 | b;
		printf("r: %i, g: %i, b: %i, color: %04x\n", r, g, b, e->colors[i]);
		// e->colors[i] = (char)(255 / num_colors * i) % 256 << 16;
		// e->colors[i] = (char)(255 / num_colors * i) % 256 << 8;
		// e->colors[i] = (char)(255 / num_colors * i) % 256;
		// on seda % vaja v?
		// e->colors[i] = e->colors[i] << 8;
		i++;
	}
}