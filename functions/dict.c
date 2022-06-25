/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:23:19 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/25 15:31:23 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>	// open
#include <unistd.h> // close, read, write
#include <stdlib.h>	// malloc

#include <stdio.h> //DEBUGGGGG

int open_file(const char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	
	return (fd);
}

int close_file(int fd)
{
	return (close(fd));
}

char *read_file(int fd)
{
	char *buffer;
	buffer = malloc(sizeof(char) * 300);
	if (!buffer)
		return (0);
	read(fd, buffer, 256);
	buffer[299] = 0;
	return (buffer);
}

int main(void)
{
	char *filename = "numbers.dict";
	char *buffer;
	int fd = open_file(filename);
	if (fd < 0)
		return (-1);
	buffer = read_file (fd);
	if (!buffer)
		return (-1);
	close_file(fd);
	printf("%s", buffer);
	return (0);
}