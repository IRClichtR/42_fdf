/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:18:01 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/21 17:12:50 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_words(char **all_lines)
{
	int		width;
	int		i;

	width = get_width(all_lines);
	if (width == -1)
		return (-1);
	i = 0;
	while (all_lines[i])
	{
		if (word_count(all_lines[i], ' ') != width)
			return (-1);
		i++;
	}
	return (1);
}
