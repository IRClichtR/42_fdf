/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_absval.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:30:30 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/26 12:48:57 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtools.h"

int	define_absval(float value)
{
	int	res;

	if (value < 0)
		res = -value;
	else
		res = value;
	return (res);
}
