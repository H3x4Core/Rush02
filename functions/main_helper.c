/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:30:54 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/26 19:48:51 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *forge_filename(char *file)
{	
	char	filename[300];
	char	*forged;
	int		len;
	filename[0] = 0;
	ft_strcat(filename, "./dictionaries/");
	ft_strcat(filename, file);
	len = ft_strlen(filename);
	forged = malloc(sizeof(char) * len);
	if (!forged)
		return (0);
	copy_buffer(filename, forged, len);
	return (forged);
}

int	check_validity(char *str)
{
	int	i;
	int	new_line_flag;

	if (!str)
		return (0);
	new_line_flag = 1;
	i = 0;
	while (str[i])
	{
		if (new_line_flag)
			if (! (line_is_valid(&str[i])))
				return (0);
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
	//int				ret;
    char			*str;
    unsigned int	r;
    
    str = malloc(10000);

    //ret = 
	read(0, str, 10000);
    r = ft_atoi(str);
    free(str);
    return (r);
}

void	translate(char *filename, long long int value)
{
	t_dict			*dict;
	t_num			s_split;
	unsigned int	*int_array;
	char			**end_str;
	int				i;

	int_array = (unsigned int *)malloc(17 * sizeof(int));
	dict = dict_from_file(filename);
	dict_sort(dict);
	s_split = split_chunks(value);
	int_array = nums_as_ints(s_split, int_array);
	end_str = humanize(int_array, dict);
	i = 0;
	while (end_str[i])
	{
		ft_putstr(end_str[i]);
		ft_putstr(" ");
		i++;
	}
	free(int_array);
}
