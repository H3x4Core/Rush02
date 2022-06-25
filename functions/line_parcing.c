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

int	line_is_valid(char *str, int start, int end)
{
	char	*oldpos;

	oldpos = str;
	while (ft_is_numeric(*str))
			str++;
	while (oldpos < str && *str == ' ')
		str++;
	if (oldpos == str)
		return (0);
	if (*str != ':')
		return (0);
	str++;
	while (*str == ' ')
		str++;
	if (ft_is_printable(*str))
		return (1);
	return (0);
}
	// while (ft_isspace(*str))
	// 	str++;
	// printf("got here[%c]\n", *str);
	// while (ft_is_printable(*str))
	// {
	// 	str++;
	// 	if (*str == '\n' || *str == '\0')
	// 		return (1);
	// }

int	line_to_num(char *str)
{
	int	num;
	
	num = 0;
	while (ft_is_numeric(*str))
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num);
}

char *line_to_words(char *str)
{
	char	*words;
	int		i;
	int 	j;

	j = 0;
	while (str[j] != ':')
		j++;
	j++;
	while (ft_isspace(str[j]))
		j++;
	i = 0;
	while (str[j + i] != '\n' && str[j + i])
		i++;
	words = (char *)malloc(sizeof(words) * i + 1);
	if (!words)
		return (NULL);
	i = 0;
	while (str[j] != '\n' && str[j])
	{
		words[i] = str[j];
		i++;
		j++;
	}
	words[i] = '\0';
	return (words);
}

/*
int main(int ac, char **av)
{
	printf("%d\n", line_to_num(av[1]));
	printf("%s\n", line_to_words(av[1]));
	printf("line valid:%d\n", line_is_valid(av[1]));
	return 0;
}
*/