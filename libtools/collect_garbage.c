/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_garbage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:44:44 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/24 17:36:51 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtools.h"

void	collect_garbage(int **ptr, t_list *garbage)
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

