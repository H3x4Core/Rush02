/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:37:02 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/26 00:54:05 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long unsigned int	line_to_num_check(char *str)
{
	long unsigned int	num;
	int					i;

	i = 0;
	num = 0;
	while (ft_is_numeric(*str))
	{
		num = num * 10 + (*str - '0');
		str++;
		if (i++ > 10 || num > 4294967295)
			return (4294967295);
	}
	return (num);
}

char	*get_first_valid_line(char *str, unsigned int *n)
{
	*n = (unsigned int)line_to_num_check(str);
	while (line_is_valid(str) && *n == 4294967295 && *str)
	{
		str = line_to_end(str) + 1;
		*n = (unsigned int)line_to_num_check(str);
	}
	return (str);
}

t_dict	*dict_from_file(char *filename)
{
	t_dict			*dict;
	t_dict			*next;
	char			*str;
	unsigned int	n;

	str = read_file(filename);
	if (!str)
		return (0);
	str = get_first_valid_line(str, &n);
	if (line_is_valid(str) && n != 4294967295)
		dict = dict_create_elem(line_to_words(str), n);
	if (!dict)
		return (0);
	next = dict;
	while (*str)
	{
		n = (unsigned int)line_to_num_check(str);
		if (line_is_valid(str) && n != 4294967295
			&& !dict_find_nbr(dict, (unsigned int)n))
			next = dict_append_elem(next, line_to_words(str), n);
		str = line_to_end(str) + 1;
	}
	return (dict);
}

#if 0

int	main(void)
{
	t_dict	*dict;
	char	*str;

	str = "../dictionaries/wrong.dict";
	dict = dict_from_file(str);
	dict_sort(dict);
	debug_print_dict(dict, "file to dict sorted");
	return (0);
}

#endif