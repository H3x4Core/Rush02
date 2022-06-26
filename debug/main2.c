/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:13:36 by znichola          #+#    #+#             */
/*   Updated: 2022/06/26 17:35:40 by matwinte         ###   ########.fr       */
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
	int		len;
	char	buffer[BUF_SIZE + 1];
	char	*str;
	unsigned int n;
	len = read(0, buffer, BUF_SIZE);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0); //CHANGE TO SOMETHING ELSE
	copy_buffer(str, buffer, len);
	n = ft_atoi(str);
	free(str);
	return (n);
}

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

int	main(int argc, char **argv)
{
	char			*filename;
	unsigned int	value;
	t_num			s_split;
	unsigned int	*int_array;
	t_dict			*dict;

	int_array = malloc(10000);
	// CHECK ARGUMENTS
	if (argc > 3)	//If more than 2
		return (0);
	else if (argc == 1) //If none
		argv[1] = "10";
		//value = get_value_from_entry();
	else
		value = ft_atoi(argv[argc - 1]);	//else get the number in value
	if (argc == 2 || argc == 1)
		filename = forge_filename("numbers.dict");	//no dictionary provided
	else
		filename = forge_filename(read_file(argv[1]));
	//if (value >= 0 && check_validity(filename))
	//{
		dict = dict_from_file(filename);
		dict_sort(dict);
		debug_print_dict(dict, "test");
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
	//}
	ft_putstr("\n");
	return (0);
}
