/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parcing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:07:26 by znichola          #+#    #+#             */
/*   Updated: 2022/06/25 16:07:28 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	line_is_valid(char *str)
{
	while (*str)
	{
		//something something
		str++;
	}
	return (1);
}

int	line_to_num(char *str)
{
	while (*str)
	{
		//something something
		str++;
	}
}

char *line_to_words(char *str)
{
	char	words
	while (*str)
	{
		//something something
		str++;
	}
}

int main(int ac, char **av)
{
	ac -= 1;
	av += 1;
	for (int i = 0; i < ac; i++)
	{
		t_dict entry1;

		entry1.n = line_to_num(av[i]);
		entry1.words = line_to_words(av[i]);
		
		t_num n = split_chunks(ft_atoi(av[i]));
		printf("num:%lld\nh:%d\nt:%d\nm:%d\nb:%d\n\n", 
	}

}
