/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:23:19 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/26 16:43:51 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	copy_buffer(char *buffer, char *str, int len)
{
	int i;
	
	i = -1;
	while (++i < len)
		str[i] = buffer[i];
}

char	*read_file(char *filename)
{
	char	buffer[BUF_SIZE + 1];
	int		fd;
	int		len;
	char	*str;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	len = read(fd, buffer, BUF_SIZE);
	close(fd);
	str = malloc(sizeof(char) * len);
	if (!str)
		return (0);
	if (!len)
	{
		free(str);
		return (0);
	}
	copy_buffer(buffer, str, len);
	return (str);
}
/*
#include <stdio.h> //DEBUGGGGG
int	main(void)
{
	char	*filename = "../dictionaries/numbers.dict";
	char	*buffer;
	buffer = ft_read_file(filename);
}*/