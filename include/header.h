/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:25:14 by znichola          #+#    #+#             */
/*   Updated: 2022/06/25 17:47:39 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

# define ERROR = -1
# define DICT_ERROR = -2
# define ERROR_MSG = "Error\n"
# define DIC_ERROR_MSG = "Dict Error\n"
# define BUF_SIZE 4096

/*stors the input number split into goups of 3 dgits*/
typedef struct s_num
{
	int	h;
	int	k;
	int	m;
	int	b;

}	t_num;

typedef struct s_dict
{
	unsigned int	n;
	char 			*words;
	struct s_dict	*next;

}					t_dict;

t_num			split_chunks(long long int num);
long long int	ft_atoi(char *str);
int				ft_is_numeric(char c);
int				ft_isspace(char c);
void			ft_putstr(char *str);
int				*nums_as_ints(t_num nums, int *int_array);
void			split_number(int nbr, int *array, int *i);
int				ft_is_printable(char c);
int				line_is_valid(char *str);
int				line_to_num(char *str);
char 			*line_to_words(char *str);
char			*read_file(char *filename);
int	ft_strlen(char *str);
char    *line_to_end(char *str);

#endif