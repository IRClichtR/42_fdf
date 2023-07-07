/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2char_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:11:29 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/07 12:11:31 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtools.h"

void	free_2char_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str[i]);
	free(str);
	str = NULL;
}
