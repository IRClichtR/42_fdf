/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_garbage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:44:44 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/31 13:29:13 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtools.h"

void	collect_2int_garbage(int **ptr, t_list *garbage)
{
	int	i;

	i = 0;
	dump_add(ptr, garbage);
	while (ptr[i])
	{
		dump_add(ptr[i], garbage);
		i++;
	}
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
