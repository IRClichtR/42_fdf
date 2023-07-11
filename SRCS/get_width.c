/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:07:49 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/11 10:07:42 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(char	**all_lines)
{
	int		count;
	int		i;
	int		partial_count;

	i = 0;
	count = word_count(all_lines[0], ' ');
	while (all_lines[i + 1])
	{
		partial_count = word_count(all_lines[i + 1], ' ');
		if (partial_count > count)
			count = partial_count;
		i++;
	}
	return (count);
}
