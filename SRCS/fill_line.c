/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:24:04 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/24 17:03:11 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_line(char *line, int *mtx_line)
{
	char	**nbr;
	t_list	*garbage;
	int		i;

	i = 0;
	nbr = ft_split(line, ' ');
	garbage = ft_calloc(1, sizeof(t_list));
	collect_garbage((int **)nbr, garbage);
	while (nbr[i] != 0)
	{
		mtx_line[i] = ft_atoi(nbr[i]);
		i++;
	}
	free(line);
	dump_del(garbage);
}
