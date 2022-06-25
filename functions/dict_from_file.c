/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:37:02 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/25 21:37:46 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

t_dict	*dict_from_file(char *filename)
{
	t_dict			*dict;
	t_dict			*next;
	char			*str;
	
	str = read_file(filename);
	if (!str || !line_is_valid(str))
		return (0);
	dict = dict_create_elem(line_to_words(str), line_to_num(str));
	if (!dict)
		return (0);
	next = dict;
	while (str)
	{
		if (!line_is_valid(str))
			return (0);
		next = dict_append_elem(next, line_to_words(str), line_to_num(str));
		str = line_to_end(str) + 1;	
	}
	return (dict);
}