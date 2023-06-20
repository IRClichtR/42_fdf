/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtools.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:27:01 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/20 15:25:44 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTOOLS_H
# define LIBTOOLS_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		check_num(char *arg);
void	collect_2int_garbage(int **ptr, int size, t_list *garbage);
void	collect_2char_garbage(char **str, t_list *garbage);
int		define_absval(float value);
int		define_max(float a, float b);
void	dump_add(void *content, t_list *garbage);
void	dump_del(t_list *garbage);
void	free_2char_str(char **str);
int		ft_atoi_base(char *str, char *base);
char	*get_a_line(int fd);
char	**get_all_lines(char *filename);
int		get_line_size(char *str);
char	*join_nfree(char **s1, char *s2);
char	**super_strdup(char **av, int ac);
int		get_len(char **str);
int		word_count(char *str, char charset);
#endif
