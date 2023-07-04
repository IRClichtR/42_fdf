/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:06:53 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/04 15:25:58 by ftuernal         ###   ########.fr       */
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
#  define WIDTH 1000
# endif
# ifndef HEIGHT
#  define HEIGHT 800
# endif

typedef struct	s_map
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
/*
typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
}				t_point;

typedef struct	s_fpoint
{
	float	x;
	float	y;
	float	z;
	float	x_inc;
	float	y_inc;
	float	z_inc;
}				t_fpoint;
typedef struct	s_step
{
	int	dx;
	int	dy;
	int	step;
}				t_step;

typedef struct	s_pix
{
	int	x;
	int	y;
}				t_pix;
*/
typedef struct	s_vector
{
	/*float*/int	x;
	/*float*/int	y;
	/*float*/int	x1;
	/*float*/int	y1;
}				t_vector;

typedef struct	s_point
{
	/*float*/int	x_dot;
	/*float*/int	y_dot;
	int		z_dot;
	/*float*/int	x1_dot;
	/*float*/int	y1_dot;
	int		z1_dot;
	float	dx;
	float	dy;
	int		max;
}				t_point;

int		check_coord(char **line);
int		check_hex(char *str_nb);
int		check_map(char **all_lines);
int		check_words(char **all_lines);
int		check_z(char	**all_lines);
int 	close_window(t_map *map);
//void    draw_line(t_map *map, t_point *p1, t_point *p2);
void    draw_line(t_vector *crd, float x1, float y1, t_map *map);
void    delete_matrix(t_map* map);
void	draw_all_lines(t_map *map);
void	fill_line(char *line, int *mtx_line, int *color_matrix);
void    make_topo(int *x, int *y, int z);
int		get_height(char **all_lines);
int		get_width(char **all_lines);
void	init_window(t_map *map);
int		press_key(int keycode, t_map *map);
void	read_file(t_map *map, char **all_lines);
void	vector_init(t_vector *crd);
//void    vector_mod_value(t_vector *crd, char *name);
#endif
