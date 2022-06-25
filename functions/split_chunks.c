/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_chunks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:27:18 by znichola          #+#    #+#             */
/*   Updated: 2022/06/25 14:27:20 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_num	split_chunks(long long int num)
{
	t_num	n;
	
	n.h = num % 1000;
	n.k = (num / 1000) % 1000;
	n.m = (num / 1000000) % 1000;
	n.b = (num / 1000000000) % 1000;
	return (n);
}

/*
#include <stdio.h>
int main(int ac, char **av)
{
	ac -= 1;
	av += 1;
	for (int i = 0; i < ac; i++)
	{
		t_num n = split_chunks(ft_atoi(av[i]));
		printf("num:%lld\nh:%d\nt:%d\nm:%d\nb:%d\n\n", 
		ft_atoi(av[i]), n.h, n.k, n.m, n.b);
	}
	return (0);
}
*/