/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_human.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:49:09 by mpouce            #+#    #+#             */
/*   Updated: 2022/06/26 22:13:25 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/* ************************************************************************** *
Create a 2d string array in the language of the dict

Input:
	- unsigned int	*array  : array containing the numbers to translate
	- t_dict	*dict_start : pointer to the first dict in our chained list
Output:
	- char	*str			: 2d array containing string in selected language
* ************************************************************************** */
char	**humanize(unsigned int	*array, t_dict *dict_start)
{
	unsigned int	i;
	char			**str_array;
	t_dict			*dict_list;

	str_array = malloc(1000);
	i = 0;
	while (array[i] != 0 || i == 0)
	{
		dict_list = dict_start;
		while (dict_list->n != array[i])
		{
			dict_list = dict_list->next;
		}
		str_array[i] = dict_list->words;
		i++;
	}
	return (str_array);
}

/* ************************************************************************** *
Check that the input does not contain anything else than numbers and \n

Input:
	- char	*str	: input received from the main function
Output:
	- int			: value being 1 if everything is correct, -1 otherwise
* ************************************************************************** */
int	check_value(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (! (ft_is_numeric(str[i])))
			return (-1);
		i++;
	}
	return (1);
}

/* ************************************************************************** *
Check the validity of the dict

Input:
	- unsigned int	*array  : array containing the numbers to translate
	- t_dict	*dict_start : pointer to the first dict in our chained list
Output:
	- char	*str			: 2d array containing string in selected language
* ************************************************************************** */
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

unsigned int	get_value_from_entry(void)
{
	char			*str;
	unsigned int	r;

	str = malloc(4096);
	if (!str)
		return (0);
	read(0, str, 4096);
	if (check_value(str) == -1)
	{
		free(str);
		return (-1);
	}
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
	free(end_str);
	free(int_array);
	dict_free(dict);
}
