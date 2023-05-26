/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:06:53 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/26 14:23:15 by ftuernal         ###   ########.fr       */
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
}				t_map;

typedef struct	s_vector
{
	int	x;
	int	y;
	int	x1;
	int	y1;
}				t_vector;

int		check_map(char *filename);
int		check_words(char *filename);
int		check_z(char	*filename);
int 	close_window(t_map *map);
void	draw_line(t_vector *coord, t_map *map);
void	fill_line(char *line, int *mtx_line);
int		get_height(char *file_name);
int		get_width(char *file_name);
void	init_window(t_map *map);
void	read_file(t_map *map, char *file_name);
void	vector_init(t_vector *crd);
#endif
