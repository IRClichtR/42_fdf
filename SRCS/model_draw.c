#include "fdf.h"

void	make_3d(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	draw_line(float x, float y, float x1, float y1, t_map *map)
{
	float	x_step;
	float	y_step;
	int	max;
	int	z;
	int	z1;

	z = map->z_matrix[(int)y][(int)x];
	z1 = map->z_matrix[(int)y1][(int)x1];

	map->zoom = 20;
	x *= map->zoom;
	y *= map->zoom;
	x1 *= map->zoom;
	y1 *= map->zoom;

	map->color = (z || z1) ? 0xe80c0c : 0xffffff;

	make_3d(&x, &y, z);
	make_3d(&x1, &y1, z1);

x += 350;
y += 350;
x1 += 350;
y1 += 350;

	x_step = x1 - x;
	y_step = y1 - y;
	max = define_max(x_step, y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(map->mlx_ptr, map->img_ptr, x, y, map->color);
		x += x_step;
		y += y_step;
	}
}

void	draw_all_lines(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				draw_line(x, y, x + 1, y, map);
			if (y < map->height - 1)
				draw_line(x, y, x, y + 1, map);
			x++;
		}
		y++;
	}
}
