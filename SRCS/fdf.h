/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:06:53 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/24 13:35:45 by ftuernal         ###   ########.fr       */
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

int		check_map(char *arg);
int		check_num(char *arg);
int		check_words(int fd);
int		check_z(int	fd);
int		get_height(char *file_name);
int		get_width(char *file_name);
void	read_file(t_map *map, char *file_name);
#endif
