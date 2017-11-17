/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:10:56 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/17 14:43:14 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft/megalibft.h"
# include <stdio.h>

typedef struct		s_room
{

}					t_room;

typedef struct		s_link
{

}					t_link;


typedef struct		s_lem
{
	int				ants;
}					t_lem;
/*
** -------------------------------- read.c ----------------------------------
*/
int		start_command(t_lem *lem);
int		ant_count(t_lem *lem);
/*
** -------------------------------- lemin.c ---------------------------------
*/
int			error_handling(void);
/*
** -------------------------------- init.c ----------------------------------
*/
t_lem		*init_struct(void);
void		init_link(t_lem *lem);
void		init_room(t_lem *lem);
#endif
