/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:37:25 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/29 14:33:34 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	define_color(t_fpoint *fp, t_map *map)
{
	
	if (map->color_matrix[(int)fp->y][(int)fp->x] > 0)
		map->color = map->color_matrix[(int)fp->y][(int)fp->x];
	else
	{
		if (fp->z < 0)
			map->color = 0x7fbfbf;/*bleu*/
		else if (fp->z == 0)
			map->color = 0x7fbfbf;/*vert*/
		else if (fp->z >= 1 && fp->z <= 15)
			map->color = 0x7fbf7f;/*vert fonce*/
		else if (fp->z > 15 && fp->z <= 25)
			map->color = 0xd6a36e;/*marron clair*/
		else
			map->color = 0xa18c76;/*marron fonce*/
	}
}

static void	define_shape(t_step *bres, t_fpoint *fp, t_point *p1, t_point *p2)
{
	bres->dx = p2->x - p1->x;
	bres->dy = p2->y - p1->y;
	bres->step = define_max(bres->dx, bres->dy);
	fp->x_inc = bres->dx / (float)bres->step;
	fp->y_inc = bres->dy / (float)bres->step;
	fp->z_inc = (p2->z = p1->z) / (float)step;
	fp->x = p1->x;
	fp->y = p1->y;
	fp->z = p1->z;
}

void	draw_line(t_map *map, t_point *p1, t_point *p2)
{
	t_step		*bres;
	t_fpoint	*fp;
	t_pix		pixel;
	int			i;

	i = 0;
	bres = ft_calloc(1, sizeof(t_step));
	fp = ft_calloc(1, sizeof(t_fpoint));
	define_shape(bres, fp, p1, p2);
	while (i <= step)
	{
		map->color = define_color();
		pixel.x = (int)fp->x;
		pixel.y = (int)fp->y - (int)(fp->z * 0.5);
		mlx_pixel_put(map->mlx_ptr, map->img_ptr, pixel.x, pixel.y, map->color);
		fp->x += fp->x_inc;
		fp->y += fp->y_inc;
		i++;
	}
	free(bres);
	free(fp);
}

























































/*
static void	define_point(t_vector *crd, int x1, int y1, t_point *point)
{
	point->x_dot = crd->x;
	point->y_dot = crd->y;
	point->x1_dot = x1;
	point->y1_dot = y1;
}

static void	define_z(t_point *point, t_map *map)
{
	float	x;
	float	y;
	float	x1;
	float	y1;

	x = point->x_dot;
	y = point->y_dot;
	x1 = point->x1_dot;
	y1 = point->y1_dot;
	point->z_dot = map->z_matrix[(int)y][(int)x];
	point->z1_dot = map->z_matrix[(int)y1][(int)x1];
}
static void	define_zoom(t_point *point, t_map * map)
{
	point->x_dot *= map->zoom;
	point->y_dot *= map->zoom;
	point->x1_dot *= map->zoom;
	point->y1_dot *= map->zoom;
}

static void	define_step(t_point *point)
{
	point->dx = point->x1_dot - point->x_dot;
	point->dy = point->y1_dot - point->y_dot;
	point->max = define_max(point->dx, point->dy);
	point->dx /= point->max;
	point->dy /= point->max;
}

void	draw_line(t_vector *crd, int x1, int y1, t_map *map)
{
	t_point	*point;

	point = ft_calloc(1, sizeof(t_point);
	define_point(crd, x1, y1, point);


	free(point);
}
*/

/*
void	draw_line(t_vector *crd, float x1, float y1, t_map *map)
{
	t_point		*point;

	point = ft_calloc(1, sizeof(t_point));

	define_point(crd, x1, y1, point);
	define_z(point, map);
	define_color(point, map);
	define_zoom(point, map);
	define_step(point);
//	make_topo(&point->x_dot, &point->y_dot, point->z_dot);
//	make_topo(&point->x1_dot, &point->y1_dot, point->z_dot);
	while ((int)(point->x_dot - point->x1_dot) != 0 
	|| (int)(point->y_dot - point->y1_dot) != 0)
	{
		mlx_pixel_put(map->mlx_ptr, map->img_ptr, point->x_dot, point->y_dot, map->color);
		point->x_dot += point->dx;
		point->y_dot += point->dy;
	}
	free(point);
}
*/
