/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:47:34 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/26 15:22:44 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtools.h"

int	word_count(char *str, char charset)
{
	int		count;
	char	**split_str;
	t_list	*garbage;

	garbage = ft_calloc(1, sizeof(t_list));
	split_str = ft_split(str, charset);
	collect_2char_garbage(split_str, garbage);
	count = get_len(split_str);
	dump_del(garbage);
	return (count);
}
