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
/*
#include <stdio.h>
#include <stdlib.h>

// Temp typedef for tests, to remove after
typedef struct s_num
{
	int	h;
	int	k;
	int	m;
	int	b;

}	t_num;
// End to typedef for tests, don't forget to remove*/

#include "../include/header.h"

void	split_number(int nbr, int *array, int *i)
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
		array[*i + 1] = nbr % 10;
		*i += 2;
	}
	else
	{
		array[*i] = (nbr % 100);
		*i += 1;
	}
}

int	*nums_as_ints(t_num nums, int *int_array)
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
	if (nums.h > 0)
		split_number(nums.h, int_array, &i);
	return (int_array);
}

// Testing with 7 131 456
// Should result in 7 1000000 100 30 1 1000 4 100 50 6
/*
int main(void)
{
	t_num	nums;
	int		*int_array;
	int		i;

	int_array = (int *)malloc(12 * sizeof(int));
	nums.h = 15;
	nums.k = 0;
	nums.m = 0;
	nums.b = 0;
	i = 0;

	int_array = nums_as_ints(nums, int_array);
	
	for (i = 0; i < 15; i++)
	{
		printf("%d ", int_array[i]);
	}
}*/