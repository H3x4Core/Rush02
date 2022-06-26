/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:23:19 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/26 02:11:08 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*read_file(char *filename)
{
	char	dict_str[BUF_SIZE + 1];
	int		fd;
	int		len;
	int		i;
	char	*test;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return ("coucou");
	test = malloc(100000);
	len = read(fd, dict_str, BUF_SIZE);
	close(fd);
	i = 0;
	while (i < len)
	{
		test[i] = dict_str[i];
		i++;
	}
	return (test);
}
/*
#include <stdio.h> //DEBUGGGGG
int	main(void)
{
	char	*filename = "../dictionaries/numbers.dict";
	char	*dict_str;
	dict_str = ft_read_file(filename);
}*/