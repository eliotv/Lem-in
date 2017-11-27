/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:10:56 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/17 15:58:17 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft/megalibft.h"
# include <stdio.h>

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	struct s_room	*next;
}					t_room;

typedef struct		s_link
{
	char 			**links;
}					t_link;


typedef struct		s_lem
{
	int				ants;
	int				flag;
	t_link			link;
	t_room			*room;
}					t_lem;
/*
** -------------------------------- read.c ----------------------------------
*/
void    link_store(t_lem *lem, char *line);
void    room_store(t_lem *lem, char *line);
/*
** -------------------------------- read.c ----------------------------------
*/
int		ant_count(t_lem *lem);
void	check_format(t_lem *lem);
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
