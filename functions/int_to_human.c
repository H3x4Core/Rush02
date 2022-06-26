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
			//printf("checking number %d\n", dict_list->n); //DEBUG
			dict_list = dict_list->next;
		}
		str_array[i] = dict_list->words;
		i++;
	}
	return (str_array);
}
/*
int main(void)
{
	t_dict	elem1;
	t_dict	elem2;
	t_dict	elem3;
	t_dict	elem4;
	t_dict	elem5;
	t_dict	elem6;
	t_dict	elem7;
	t_dict	elem8;
	t_dict	*begin;

	elem1.n = 10;
	elem1.words = "ten";
	elem1.next = &elem2;
	
	elem2.n = 1000;
	elem2.words = "thousand";
	elem2.next = &elem3;

	elem3.n = 12;
	elem3.words = "twelve";
	elem3.next = &elem4;

	elem4.n = 100;
	elem4.words = "hundred";
	elem4.next = &elem5;

	elem5.n = 1;
	elem5.words = "one";
	elem5.next = &elem6;

	elem6.n = 90;
	elem6.words = "ninety";
	elem6.next = &elem7;

	elem7.n = 2;
	elem7.words = "two";
	elem7.next = &elem8;

	elem8.n = 1000000;
	elem8.words = "million";
	elem8.next = 0;

	begin = &elem1;
	
	int	*int_array = malloc(10);
	int_array[0] = 1;
	int_array[1] = 1000000;
	int_array[2] = 12;
	int_array[3] = 1000;
	int_array[4] = 90;
	int_array[5] = 2;
	int_array[6] = 0;

	char **str_array = humanize(int_array, begin);
	for (int loop = 0; loop < 7; loop++)
	{
		printf("%d ", int_array[loop]);
		printf("%s\n", str_array[loop]);
	}
	return (0);
}*/