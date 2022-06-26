/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:23:19 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/26 21:34:13 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	copy_buffer(char *buffer, char *str, int len)
{
	int i;

	i = -1;
	while (++i < len)
		str[i] = buffer[i];
	i++;
	str[i] = 0;
}

/* ************************************************************************** *
Create a new element

Input:
	- char *filename : str containing the name of the file to open
Output:
	- char *str : whole dictionary contained in a single string
* ************************************************************************** */
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
	str = malloc(sizeof(char) * len + 1);
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
