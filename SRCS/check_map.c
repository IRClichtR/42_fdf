/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:04:15 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/20 16:07:30 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_map(char **all_lines)
{
	if (check_words(all_lines) == 1)
		return (1);
	if (check_z(all_lines) == 1)
	{
		return (1);
	}
	else if (check_coord(all_lines) == 1)
		return (1);
	else
	{
		free_2char_str(all_lines);
		ft_putstr_fd("Error: Invalid map\n", 2);
		return (-1);
	}
}
