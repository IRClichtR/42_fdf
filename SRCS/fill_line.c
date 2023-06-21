/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:24:04 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/21 14:07:38 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_nb_color(char **nbr, int *mtx_line, int *color_mtx)
{
	char	**temp;
	char	*hex;
	int		i;

	i = 0;
	while (nbr[i] != 0)
	{
		temp = ft_split(nbr[i], ',');
		mtx_line[i] = ft_atoi(temp[0]);
		if (temp[1])
		{
			hex = ft_substr(temp[1], 2, ft_strlen(temp[1]) - 2);
			color_mtx[i] = ft_atoi_base(hex, "0123456789ABCDEF");
			free(hex);
		}
		free_2char_str(temp);
		i++;
	}
}

void	fill_line(char *line, int *mtx_line, int *color_mtx)
{
	char	**nbr;
	t_list	*garbage;
	int		i;

	i = 0;
	nbr = ft_split(line, ' ');
	garbage = ft_calloc(1, sizeof(t_list));
	collect_2char_garbage(nbr, garbage);
	if (ft_strchr(line, ',') != 0)
		get_nb_color(nbr, mtx_line, color_mtx);
	else
	{
		while (nbr[i] != 0)
		{
			mtx_line[i] = ft_atoi(nbr[i]);
			color_mtx[i] = -1;
			i++;
		}
	}
	free(line);
	dump_del(garbage);
}
/*
int main(int ac, char **av)
{
	char	**arg;
	
	arg = ft_split(av[1], ' ');
	int	len = get_len(arg);
	int	*mtx_line = ft_calloc(len, sizeof(int));
	int	*color_mtx = ft_calloc(len, sizeof(int));
	fill_line(av[1], mtx_line, color_mtx);
	int i = 0;
		printf("CHAIN == %s\n", av[1]);
	while (i < len)
	{
		printf("z = %d | color = %d\n", mtx_line[i], color_mtx[i]);
		i++;
	}
	free(mtx_line);
	free(color_mtx);
	free_2char_str(arg);
	return (0);
}
*/
