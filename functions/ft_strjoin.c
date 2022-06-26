/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:38:57 by znichola          #+#    #+#             */
/*   Updated: 2022/06/26 20:32:39 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_str_str_len(char **str)
{
	int	i;
	int	j;
	int	sum;

	i = 0;
	sum = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			j++;
		sum += j;
		i++;
	}
	return (sum);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*r;

	r = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (r);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*str;

	len = ft_str_str_len(strs) + ft_strlen(sep) * (size -1) + 1;
	str = (char *)malloc(len * sizeof(*str));
	if (!str)
		return (NULL);
	*str = '\0';
	i = 0;
	while (i < size)
	{
		str = ft_strcat(str, strs[i]);
		i++;
		if (i < size)
			ft_strcat(str, sep);
	}
	return (str);
}
