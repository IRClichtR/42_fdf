/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_z.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:20:00 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/25 11:04:58 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_z(char **all_lines)
{
	int	i;

	i = 0;
	while (all_lines[i])
	{
		if (ft_strchr(all_lines[i], ',') != 0)
			if (check_coord(all_linesi[i]) == -1)
				return (-1);
		else if (check_num(all_lines[i]) == -1)
			return (-1);
		i++;
	}
	return (0);
}
