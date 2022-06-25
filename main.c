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
	int	i;
	int	line_start;

	i = 0;
	line_start = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\n')
			i++;
		if (!line_is_valid(&str[i]))
		{
			printf("failed : %s", &str[i]);
			return (1);
		}
		i++;
		line_start = i;
	}
	return (1);
}

int	get_value_from_entry(void)
{
	int	ret;
	char	*str;
	str = malloc(10000);

	ret = read(0, str, 30720);
	return (ft_atoi(str));
}

int	main(int argc, char **argv)
{
	char	*dict_str;
	unsigned int		value;
	t_num	s_split;
	int		*int_array;

	int_array = malloc(10000);
	if (argc > 3)
		return (0);
	else if (argc == 1)
		value = get_value_from_entry();
	else
		value = ft_atoi(argv[argc - 1]);
	if (argc == 2 || argc == 1)
		dict_str = read_file("dictionaries/numbers.dict");
	else
		dict_str = read_file(argv[1]);
	if (value >= 0 && check_validity(dict_str))
	{
		s_split = split_chunks(value);
		int_array = nums_as_ints(s_split, int_array);
		for (int i = 0; i < 15; i++)
			printf("%d ", int_array[i]);
	}
	return (0);
}
