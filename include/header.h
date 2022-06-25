/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:25:14 by znichola          #+#    #+#             */
/*   Updated: 2022/06/25 15:33:29 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define ERROR = -1
# define DICT_ERROR = -2

/*stors the input number split into goups of 3 dgits*/
typedef struct s_num
{
	int	h;
	int	k;
	int	m;
	int	b;

}	t_num;

t_num	split_chunks(long long int num);
long long int	ft_atoi(char *str);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);


typedef struct s_dict
{
	unsigned int	n;
	char 			*words;
	t_dict			*next;

}				t_dict;

#endif