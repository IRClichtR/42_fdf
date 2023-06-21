/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_topo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:41:31 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/21 16:11:15 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_topo(float *x, float *y, int z)
{
	float	x_temp;
	float	y_temp;

	x_temp = (*x - *y) * cos(0.8);
	y_temp = (*x + *y) * sin(0.8) - z;
	*x = x_temp;
	*y = y_temp;

/*
	float	temp_x;
	float	temp_y;
	float	temp_x1;
	float	temp_y1;

	temp_x = (x - y) * cos(0.8);
	temp_y = (x + y) * sin(0.8) - p->z_dot; 
	temp_x1 = (p->x1_dot - p->y1_dot) * cos(0.8);
	temp_y1 = (p->x1_dot + p->y1_dot) * sin(0.8) - p->z_dot; 
	x = temp_x;
	y = temp_y;
	p->x1_dot = temp_x1;
	p->y1_dot = temp_y1;
*/
}
