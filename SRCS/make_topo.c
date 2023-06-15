/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_topo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:41:31 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/15 12:01:05 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_topo(t_point *pt)
{
	float	temp_x;
	float	temp_y;
	float	temp_x1;
	float	temp_y1;

	temp_x = (pt->x_dot - pt->y_dot) * cos(0.8);
	temp_y = (pt->x_dot + pt->y_dot) * sin(0.8) - pt->z_dot; 
	temp_x1 = (pt->x1_dot - pt->y1_dot) * cos(0.8);
	temp_y1 = (pt->x1_dot + pt->y1_dot) * sin(0.8) - pt->z_dot; 
	pt->x_dot = temp_x;
	pt->y_dot = temp_y;
	pt->x1_dot = temp_x1;
	pt->y1_dot = temp_y1;
}
