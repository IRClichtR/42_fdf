/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtools.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:27:01 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/26 15:05:29 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTOOLS_H
# define LIBTOOLS_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

int		check_num(char *arg);
void	collect_2int_garbage(int **ptr, t_list *garbage);
void	collect_2char_garbage(char **str, t_list *garbage);
int		define_absval(float value);
int		define_max(float a, float b);
void	dump_add(void *content, t_list *garbage);
void	dump_del(t_list *garbage);
char	*join_nfree(char **s1, char *s2);
char	**super_strdup(char **av, int ac);
int		get_len(char **str);
int		word_count(char *str, char charset);
#endif
