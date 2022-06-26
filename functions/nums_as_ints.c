/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_as_ints.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouce <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:44:04 by mpouce            #+#    #+#             */
/*   Updated: 2022/06/25 13:44:06 by mpouce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/* ************************************************************************** *
Split the number to how is it humanly read

Input:
	- int nbr				: value from splitting the atoi (max 999)
	- unsigned int *array	: array that will receive the split values
	- int	*i				: pointer to the array index
Output:
	- None, value is directly written in the array
* ************************************************************************** */
void	split_number(int nbr, unsigned int *array, int *i)
{
	if (nbr / 100 > 0)
	{
		array[*i] = nbr / 100;
		array[*i + 1] = 100;
		*i += 2;
	}
	if (nbr % 100 > 19)
	{
		array[*i] = (nbr % 100) - (nbr % 10);
		if (nbr % 10 != 0)
		{
			array[*i + 1] = nbr % 10;
			*i += 1;
		}
		*i += 1;
	}
	else
	{
		if (nbr % 100 > 0)
		{
			array[*i] = (nbr % 100);
			*i += 1;
		}
	}
}

/* ************************************************************************** *
Split numbers in groups of three and add the correct separator

Input:
	- t_num	nums				: struct with numbers in groups
	- unsigned int *int_array	: array that will receive values
Output:
	- unsigned int	*int_array	: array with values as read by humans
* ************************************************************************** */
unsigned int	*nums_as_ints(t_num nums, unsigned int *int_array)
{
	int	i;

	i = 0;
	if (nums.b > 0)
	{
		split_number(nums.b, int_array, &i);
		int_array[i] = 1000000000;
		i++;
	}
	if (nums.m > 0)
	{
		split_number(nums.m, int_array, &i);
		int_array[i] = 1000000;
		i++;
	}
	if (nums.k > 0)
	{
		split_number(nums.k, int_array, &i);
		int_array[i] = 1000;
		i++;
	}
	split_number(nums.h, int_array, &i);
	return (int_array);
}
