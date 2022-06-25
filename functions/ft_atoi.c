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

int	ft_isspace(char c)
{
	return(c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

long long int	ft_atoi(char *str)
{
	long long int	n;
	int				s;

	s = 1;
	n = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s *= -1;
		str++;
	}
	while (is_numeric(*str))
	{
		n = 10 * n + *str - '0';
		if (n > 4294967295)
			return (-1);
		str++;
	}
	return (n * s);
}

/*
//gcc ft_atoi.c && ./a.out -234 13 +0 +123 -0 123.4 ++123 -+123 +-12 -13b23 -b12
#include <stdlib.h>
#include <stdio.h>
int main(int ac, char **av)
{
	ac -= 1;
	av += 1;
	for (int i = 0; i < ac; i++)
		printf("atoi:%d		ft_atoi:%lld\n", atoi(av[i]), ft_atoi(av[i]));
	// printf("%s:	%d", av[ac], ft_atoi("-1112wq32"));
	return (0);
}
*/