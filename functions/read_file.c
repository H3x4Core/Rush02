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
#define BUF_SIZE 4096

#include <stdio.h> //DEBUGGGGG

char	*read_file(char *filename)
{
	char	dict_str[BUF_SIZE + 1];
	int		fd;
	int		len;
	
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	len = read(fd, dict_str, BUF_SIZE);
	close_file(fd);
	printf("%s", dict_str);
	return (dict_str);
}
/*
int	main(void)
{
	char	*filename = "../dictionaries/numbers.dict";
	char	*dict_str;
	dict_str = ft_read_file(filename);
}*/