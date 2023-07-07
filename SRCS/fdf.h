/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:06:53 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/07 11:48:50 by ftuernal         ###   ########.fr       */
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
# include <X11/keysym.h>
# include <X11/X.h>
# include <sys/types.h>
# include <unistd.h>
# include <string.h>
# include <math.h>

# ifndef WIDTH
#  define WIDTH 1500
# endif
# ifndef HEIGHT
#  define HEIGHT 1500
# endif

typedef struct s_map
{
	int		width;
	int		height;
	int		**z_matrix;
	int		**color_matrix;
	void	*mlx_ptr;
	void	*img_ptr;
	int		zoom;
	int		color;
}				t_map;

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_point
{
	float	x_dot;
	float	x1_dot;
	float	y_dot;
	float	y1_dot;
	int		z_dot;
	int		z1_dot;
	float	dx;
	float	dy;
	int		max;
}				t_point;

int		check_coord(char **line);
int		check_hex(char *str_nb);
int		check_map(char **all_lines);
int		check_words(char **all_lines);
int		check_z(char **all_lines);
int		close_window(t_map *map);
void	define_color(t_point *pt, t_map *map);
void	define_isometric(float *x, float *y, int z);
void	define_point(t_vector *crd, float x1, float y1, t_point *point);
void	define_shift(t_point *point);
void	define_step(t_point *point);
void	define_z(t_point *point, t_map *map);
void	define_zoom(t_point *point, t_map *map);
void	delete_matrix(t_map	*map);
void	draw_line(t_vector *vector, float x1, float y1, t_map *map);
void	draw_all_lines(t_map *map);
void	fill_line(char *line, int *mtx_line, int *color_matrix);
int		get_height(char **all_lines);
int		get_width(char **all_lines);
void	init_window(t_map *map);
int		press_key(int keycode, t_map *map);
void	read_file(t_map *map, char **all_lines);
void	vector_init(t_vector *crd);
#endif
