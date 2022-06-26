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

int check_validity(char *str)
{
    int i;
    int new_line_flag;

    new_line_flag = 1;
    i = 0;
    while(str[i])
    {
        if (new_line_flag)
            if (!line_is_valid(&str[i]))
            {
                return (0);
            }
        if (str[i] == '\n')
            new_line_flag = 1;
        else 
            new_line_flag = 0;
        i++;
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
	char	*filename;
	long long int		value;

	if (argc > 3)
		return (0);
	else if (argc == 1)
		value = get_value_from_entry();
	else
		value = ft_atoi(argv[argc - 1]);
	if (argc == 2 || argc == 1)
		filename = "dictionaries/numbers.dict";
	else
		filename = argv[1];
	if (value >= 0)
	{
		if (check_validity(read_file(filename)))
			translate(filename, value);
		else
			ft_putstr("Dict Error");
	}
	else
		ft_putstr("Error");
	ft_putstr("\n");
	return (0);
}

void	translate(char *filename, long long int value)
{
	t_dict	*dict;
	t_num	s_split;
	unsigned int		*int_array;

	int_array = (unsigned int *)malloc(17 * sizeof(int));
	dict = dict_from_file(filename);
	dict_sort(dict);
	s_split = split_chunks(value);
	int_array = nums_as_ints(s_split, int_array);
	char **end_str = humanize(int_array, dict);
			
	int i = 0;
	while (end_str[i])
	{
		ft_putstr(end_str[i]);
		ft_putstr(" ");
		i++;	
	}
	free(int_array);
}