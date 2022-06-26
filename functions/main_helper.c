/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:30:54 by matwinte          #+#    #+#             */
/*   Updated: 2022/06/26 20:07:19 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *forge_filename(char *file)
{	
	char	filename[300];
	char	*forged;
	int		len;
	filename[0] = 0;
	ft_strcat(filename, "./dictionaries/");
	ft_strcat(filename, file);
	len = ft_strlen(filename);
	forged = malloc(sizeof(char) * len);
	if (!forged)
		return (0);
	copy_buffer(filename, forged, len);
	return (forged);
}
