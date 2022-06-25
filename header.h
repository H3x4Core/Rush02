/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matwinte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:46:43 by mwinter           #+#    #+#             */
/*   Updated: 2022/06/25 13:59:23 by matwinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

typedef struct s_dict
{
	unsigned int	n;
	char 			*word;
	t_dict			*next;

}				t_dict;


#endif
