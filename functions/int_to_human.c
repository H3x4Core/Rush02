/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_human.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:49:09 by mpouce            #+#    #+#             */
/*   Updated: 2022/06/26 01:08:21 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

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

	str_array = malloc(100000);
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

int	check_value(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (! (ft_is_numeric(str[i])))
			return (0);
		i++;
	}
	return (1);
}