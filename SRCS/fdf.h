/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:06:53 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/13 15:54:01 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../libtools/libtools.h"
# include <errno.h>
# include <sys/types.h>
# include <unistd.h>
# include <string.h>
# include <math.h>

typedef struct	s_map
{
	int		width;
	int		height;
	int		**z_matrix;
	void	*mlx_ptr;
	void	*img_ptr;
	int		zoom;
	int		color;
}				t_map;

typedef struct	s_vector
{
	float	x;
	float	y;
	float	x1;
	float	y1;
}				t_vector;

typedef struct	s_point
{
	float	x_dot;
	float	y_dot;
	float	x1_dot;
	float	y1_dot;
	float	z_dot;
	float	z1_dot;
	float	dx;
	float	dy;
	int		max;
}				t_point;

int		check_map(char **all_lines);
int		check_words(char **all_lines);
int		check_z(char	**all_lines);
int 	close_window(t_map *map);
void    draw_line(t_vector *crd, float x1, float y1, t_map *map);
void	draw_all_lines(t_map *map);
void	fill_line(char *line, int *mtx_line);
void    make_topo(t_point *pt);
int		get_height(char **all_lines);
int		get_width(char **all_lines);
void	init_window(t_map *map);
void	read_file(t_map *map, char **all_lines);
void	vector_init(t_vector *crd);
void    vector_mod_value(t_vector *crd, char *name);
#endif
