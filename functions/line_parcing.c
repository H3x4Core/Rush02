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
	if (ft_is_numeric(*str))
	{
		while (ft_is_numeric(*str))
			str++;
		while (*str == ' ')
			str++;
		if (*str == ':')
		{
			str++;
			while (*str == ' ')
				str++;
			if (ft_is_printable(*str))
			{
				while (ft_is_printable(*str))
					str++;
				if (*str == '\n')
					return (1);
			}
		}	
	}
	return (0);
}

int	line_to_num(char *str)
{
	int	num;
	
	num = 0;
	while (ft_is_numeric(*str))
	{
		num = num * 10 + *str;
		str++;
	}
	return (num);
}

char *line_to_words(char *str)
{
	char	*words;
	int		i;

	while (*str != ':')
		str++;
	while (ft_isspace(*str))
		str++;
	i = 0;
	while (str[i] != '\n')
		i++;
	return (words);
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
	}
}
