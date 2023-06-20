/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_z.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:20:00 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/20 16:05:33 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_z(char **all_lines)
{
	int	i;

	i = 0;
	if (ft_strchr(all_lines[i], ',') != 0)
	{
			if (check_coord(all_lines) == -1)
				return (-1);
	}
	else
	{
		while (all_lines[i])
		{
			if (check_num(all_lines[i]) == -1)
				return (-1);
			i++;
		}
	}
	return (1);
}
