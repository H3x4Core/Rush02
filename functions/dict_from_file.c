/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:37:02 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/26 16:46:24 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/* ************************************************************************** *
Return the number from the buffered file

Input:
	char *str : buffered file
Ouput:
	long unsigned int num :
		SUCCESS -> the str number converted to int
		FAIL 	-> 4294967295 (max unsigned int 32)
* ************************************************************************** */
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

/* ************************************************************************** *
Get the first valid line of the buffered file

Input:
	char *str : buffered file
	unsigned int *n : n of the current line
Return:
	char *str : moved to the first valid line
* ************************************************************************** */
char	*get_first_valid_line(char *str, unsigned int *n)
{
	while (!line_is_valid(str))
		str = line_to_end(str) + 1;
	*n = (unsigned int)line_to_num_check(str);
	while (line_is_valid(str) && *n == 4294967295 && *str)
	{
		str = line_to_end(str) + 1;
		*n = (unsigned int)line_to_num_check(str);
	}
	return (str);
}

t_dict	*dict_append_loop(char *str, unsigned int n, t_dict *dict, t_dict *next)
{
	while (*str)
	{
		n = (unsigned int)line_to_num_check(str);
		if (line_is_valid(str) && n != 4294967295
			&& !dict_find_nbr(dict, (unsigned int)n))
			next = dict_append_elem(next, line_to_words(str), n);
		if (!next)
			return (dict_free(dict));
		str = line_to_end(str) + 1;
	}
	return (next);
}

/*
Free the dictionary and the string if they are not pointing on void pointer
Input:
	- t_dict *dict : the address of the first item in the dictionary
	- char *str : the address of the first char of the buffered file
Output:
	- Void pointer
*/
t_dict	*combined_free(t_dict *dict, char *str)
{
	if (str)
		free(str);
	if (dict)
		dict_free(dict);
	return (0);
}

/* ************************************************************************** *
Put the dictionary from the file in the list

Input:
	char *filename : filename of the dictionary
Output:
	FAIL:		
		void pointer : malloc issue or no suitable element in the dictionary
	SUCCESS:
		t_dict	*dict : address of the first item of the dictionary

Checks:
	- buffered file do not point on void pointer
	- get first valid line of buffered file
	- create and check first element do not point on void pointer
	- create, append and check next n element do not point on void pointers
	- check for duplicate before adding new element
	- call for n with checks for overflow
	- call check for line validity
* ************************************************************************** */
t_dict	*dict_from_file(char *filename)
{
	t_dict			*dict;
	t_dict			*next;
	char			*str;
	char			*ori_str;
	unsigned int	n;

	str = read_file(filename);
	dict = 0;
	if (!str)
		return (0);
	ori_str = str;
	str = get_first_valid_line(str, &n);
	if (line_is_valid(str) && n != 4294967295)
		dict = dict_create_elem(line_to_words(str), n);
	if (!dict)
		return (combined_free(dict, ori_str));
	next = dict;
	if (!dict_append_loop(str, n, dict, next))
		return (combined_free(dict, ori_str));
	free(ori_str);
	return (dict);
}

#if 0

int	main(void)
{
	t_dict	*dict;
	char	*filename;

	filename = "../dictionaries/wrong.dict";
	dict = dict_from_file(filename);
	dict_sort(dict);
	debug_print_dict(dict, "file to dict sorted");
	return (0);
}

#endif