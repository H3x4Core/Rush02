/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parcing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:07:26 by znichola          #+#    #+#             */
/*   Updated: 2022/06/25 21:37:13 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int    line_is_valid(char *str)
{
    char    *oldpos;

    oldpos = str;

    while (ft_is_numeric(*str) || ft_isspace(*str) || *str == '+')
            str++;
    // if (ft_atoi(str) < 0)
    //     return (0);
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

char	*line_to_end(char *str)
{
	while (*str != '\n' && *str != '\0')
		str++;
	return (str);
}

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

char	*trim_line(char *str)
{
	int	i;
	int	j;
	int	spacefound;

	i = 0;
	j = 0;
	spacefound = 0;
	while (str[i + j] != '\0')
	{
		if (!ft_isspace(str[i + j]) || spacefound == 0)
		{
			spacefound = 0;
			str[i] = str[i + j];
			i++;
		}
		if (ft_isspace(str[i + j - 1]))
		{
			if (spacefound == 1)
				j++;
			spacefound = 1;
		}
	}
	str[i] = '\0';
	return (str);
}

char	*line_to_words(char *str)
{
	char	*words;
	int		i;
	int		j;

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
	return (trim_line(words));
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