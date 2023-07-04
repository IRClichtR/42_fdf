/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:37:25 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/04 15:55:31 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	define_color(t_point *pt, t_map *map)
{
	if (map->color_matrix[(int)pt->y_dot][(int)pt->x_dot] > 0)
		map->color = map->color_matrix[(int)pt->y_dot][(int)pt->x_dot];
	else
	{
		if (pt->z_dot < 0)
			map->color = 0x7fbfbf;/*bleu*/
		else if (pt->z_dot == 0)
			map->color = 0x7fbfbf;/*vert*/
		else if (pt->z_dot >= 1 && pt->z_dot <= 15)
			map->color = 0x7fbf7f;/*vert fonce*/
		else if (pt->z_dot > 15 && pt->z_dot <= 25)
			map->color = 0xd6a36e;/*marron clair*/
		else
			map->color = 0xa18c76;/*marron fonce*/
	}
}

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
printf("point->x1_dot - point->x_dot = %f\n", point->dx);
	point->dy = point->y1_dot - point->y_dot;
printf("point->y1_dot - point->y_dot = %f\n", point->dy);
	point->max = define_max(point->dx, point->dy);
printf("point->max = %d\n", point->max);
	point->dx /= point->max;
	point->dy /= point->max;
printf("final dx dy = %f %f\n", point->dx, point->dy);
}

void	draw_line(t_vector *crd, float x1, float y1, t_map *map)
{
	t_point		*point;

	point = ft_calloc(1, sizeof(t_point));

	define_point(crd, x1, y1, point);
	define_z(point, map);
	define_color(point, map);
	define_zoom(point, map);
	define_step(point);
	make_topo(&point->x_dot, &point->y_dot, point->z_dot);
	make_topo(&point->x1_dot, &point->y1_dot, point->z_dot);
	while (/*(int)*/(point->x_dot - point->x1_dot) != 0 
	|| /*(int)*/(point->y_dot - point->y1_dot) != 0)
	{
printf("point->dx %f || point->dy %f\n", point->dx, point->dy);
		mlx_pixel_put(map->mlx_ptr, map->img_ptr, point->x_dot + 10, point->y_dot + 10, map->color);
		point->x_dot += point->dx;
		point->y_dot += point->dy;
		break ;
	}
	free(point);
}

/*
static void	draw_point(t_map *map, t_point *p1, t_point *p2, int i, int j)
{
	p1->x = (j - i) * 30 + WIDTH / 2;
	p1->y = (i + j) * 15 + HEIGHT / 2 - map->z_matrix[i][j];
	p1->z = map->z_matrix[i][j];
	p2->x = (j - (i + 1)) * 30 + WIDTH / 2;
	p2->y = (j + (i + 1)) * 15 + HEIGHT / 2;
	p2->z = map->z_matrix[i + 1][j];
	draw_line(map, p1, p2);
}
void	draw_all_lines(t_map *map)
{
	t_point	*p1;
	t_point	*p2;
	int		i;
	int		j;

	i = 0;
	p1 = ft_calloc(1, sizeof(t_point));
	p2 = ft_calloc(1, sizeof(t_point));
	while (i < map->height - 1)
	{
		j = 0;
		while (j < map->width)
		{
			if (i < map->width - 1)
				draw_point(map, p1, p2, i, j);
			if (j < map->width - 1)
				draw_point(map, p1, p2, i, j);
			j++;
		}
		i++;
	}
	free_points(p1, p2);
}
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
static void	define_shape(t_step *bres, t_fpoint *fp, t_point *p1, t_point *p2)
{
	bres->dx = p2->x - p1->x;
	bres->dy = p2->y - p1->y;
	bres->step = define_max(bres->dx, bres->dy);
	fp->x_inc = bres->dx / (float)bres->step;
	fp->y_inc = bres->dy / (float)bres->step;
	fp->z_inc = (p2->z - p1->z) / (float)bres->step;
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
	while (i <= bres->step)
	{
		define_color(fp, map);
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
*/
