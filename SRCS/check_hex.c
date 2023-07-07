/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:51:54 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/07 11:54:16 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_hex(char *str_nb)
{
	char	*hex_up;
	char	*hex_low;
	int		i;
	int		j;

	i = 2;
	str_nb += 2;
	if (ft_strlen(str_nb) > 6)
		return (-1);
	hex_up = "0123456789abcdef";
	hex_low = "0123456789ABCDEF";
	while (str_nb[i])
	{
		j = 0;
		while (hex_up[j])
		{
			if (str_nb[i] == hex_up[j] || str_nb[i] == hex_low[j])
				return (1);
			j++;
		}
		i++;
	}
	return (-1);
}
