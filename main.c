/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:13:36 by znichola          #+#    #+#             */
/*   Updated: 2022/06/25 10:23:34 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_validity(char *str)
{
	(void) str;
	return (1);
}

int	main(int argc, char **argv)
{
	char	*dict_str;
	int		value;
	t_num	s_split;
	int		*int_array;

	int_array = malloc(10000);
	if (argc > 3 || argc <= 1)
		return (0);
	else if (argc == 2)
		dict_str = read_file("dictionaries/numbers.dict");
	else
		dict_str = read_file(argv[1]);
	value = ft_atoi(argv[argc - 1]);
	if (value >= 0 && check_validity(dict_str))
	{
		s_split = split_chunks(value);
		int_array = nums_as_ints(s_split, int_array);
		for (int i = 0; i < 15; i++)
			printf("%d ", int_array[i]);
	}
	return (0);

}

