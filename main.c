/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:13:36 by znichola          #+#    #+#             */
/*   Updated: 2022/06/26 18:25:08 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	char	*filename;
	long long int		value;

	if (argc > 3)
		return (0);
	else if (argc == 1)
		value = get_value_from_entry();
	else
		value = ft_atoi(argv[argc - 1]);
	if (argc == 2 || argc == 1)
		filename = forge_filename("numbers.dict");
	else
		filename = forge_filename(argv[1]);
	if (value >= 0)
	{
		if (check_validity(read_file(filename)))
			translate(filename, value);
		else
			ft_putstr("Dict Error");
	}
	else
		ft_putstr("Error");
	ft_putstr("\n");
	return (0);
}
