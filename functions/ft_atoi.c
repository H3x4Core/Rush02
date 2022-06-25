/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:38:57 by znichola          #+#    #+#             */
/*   Updated: 2022/06/16 21:39:04 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

long long int	ft_atoi(char *str)
{
	long long int	n;
	int	s; 

	s = 1;
	n = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
	{
		s *= -1;
		str++;
	}
	if (*str == '+')
	{
		s *= -1;
		str++;
	}
	if (!is_numeric(*str))
		return (0);
	n = *str - '0';
	str++;
	while (is_numeric(*str))
	{
		n = 10 * n + *str - '0';
		str++;
	}
	n *= s;
	return (n);
}


#include <stdlib.h>
#include <stdio.h>
int main(int ac, char **av)
{
	ac -= 1;
	av += 1;
	for (int i = 1; i < ac; i++)
		printf("str:%s	atoi:%d	ft_atoi:%lu\n", av[i], atoi(av[i]), ft_atoi(av[i]));
	// printf("%s:	%d", av[ac], ft_atoi("-1112wq32"));
	return (0);
}
