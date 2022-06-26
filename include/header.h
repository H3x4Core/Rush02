/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:25:14 by znichola          #+#    #+#             */
/*   Updated: 2022/06/26 18:31:33 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>	// open
# include <unistd.h> // close, read, write
# include <stdlib.h>	// malloc
# include <stdio.h>

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
	char			*words;
	struct s_dict	*next;

}					t_dict;

t_num			split_chunks(long long int num);
long long int	ft_atoi(char *str);
int				ft_is_numeric(char c);
int				ft_isspace(char c);
void			ft_putstr(char *str);
unsigned int	*nums_as_ints(t_num nums, unsigned int *int_array);
void			split_number(int nbr, unsigned int *array, int *i);
int				ft_is_printable(char c);
int				line_is_valid(char *str);
char			*line_to_end(char *str);
int				line_to_num(char *str);
char			*line_to_words(char *str);
char			*read_file(char *filename);
t_dict			*dict_from_file(char *filename);
t_dict			*dict_create_elem(char *str, unsigned int n);
t_dict			*dict_append_elem(t_dict *dict, char *str, unsigned int n);
t_dict			*dict_find_nbr(t_dict *dict, unsigned int to_find);
void			dict_sort(t_dict *dict);
t_dict			*dict_free(t_dict *current);
int				ft_strlen(char *str);
char			**humanize(unsigned int *array, t_dict *dict_start);
void			translate(char *filename, long long int value);
char			*trim_line(char *str);
void			copy_buffer(char *buffer, char *str, int len);
char			*ft_strcat(char *dest, char *src);

/******************* DEBUG ***********************/
t_dict			*hardcoded_dict(void);
void			debug_print_dict(t_dict *dict, char *str);
void			debug_print_element(t_dict *current, char *str);

#endif
