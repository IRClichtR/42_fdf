/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_garbage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:44:44 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/15 15:24:19 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtools.h"

void	collect_2int_garbage(int **ptr, int size, t_list *garbage)
{
	int	i;

	i = 0;
	dump_add(ptr, garbage);
	while (i < size)
	{
		dump_add(ptr[i], garbage);
		i++;
	}
	dump_add(ptr, garbage);
}

void	collect_2char_garbage(char **str, t_list *garbage)
{
	int	i;

	i = 0;
	dump_add(str, garbage);
	while (str[i])
	{
		dump_add(str[i], garbage);
		i++;
	}
//	dump_add(str[i], garbage);
}
