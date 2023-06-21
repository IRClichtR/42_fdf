/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:07:49 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/21 17:13:43 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(char	**all_lines)
{
	int		count;
	int		i;

	count = word_count(*all_lines, ' ');
	i = 1;
	while (all_lines[i])
	{
		if (word_count(all_lines[i], ' ') != count)
			return (-1);
		i++;
	}
	return (count);
}
