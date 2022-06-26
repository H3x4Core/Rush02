/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:38:57 by znichola          #+#    #+#             */
/*   Updated: 2022/06/26 20:31:55 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
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
	if (!ft_is_numeric(*str))
		return (-1);
	while (ft_is_numeric(*str))
	{
		n = 10 * n + *str - '0';
		if (n > 4294967295)
			return (-1);
		str++;
	}
	return (n * s);
}
