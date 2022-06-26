/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:20:27 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/26 18:25:05 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *forge_filename(char *file)
{	
	char	filename[300];
	char	*forged;
	int		len;
	filename[0] = 0;
	ft_strcat(filename, "../dictionaries/");
	ft_strcat(filename, file);
	len = ft_strlen(filename);
	forged = malloc(sizeof(char) * len);
	if (!forged)
		return (0);
	copy_buffer(filename, forged, len);
	return (forged);
}

int check_validity(char *str)
{
    int i;
    int new_line_flag;

	if (!str)
		return (0);
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
	int			len;
	char		buffer[BUF_SIZE + 1];
	char		*str;
	long int	n;
	len = read(0, buffer, BUF_SIZE);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (-1);
	copy_buffer(str, buffer, len);
	n = ft_atoi(str);
	free(str);
	return (n);
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
