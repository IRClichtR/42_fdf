/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:18:01 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/31 14:27:01 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_words(char **all_lines)
{
	int		width;
	int		i;

	width = get_width(all_lines);
	while (all_lines[i])
	{
		if (word_count(all_lines[i], ' ') != width)
		{
			dump_del(dump);
			return (-1);
		}
		i++;
	}
	dump_del(dump);
	return (0);
}
