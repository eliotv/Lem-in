/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:10:56 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/30 14:08:43 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft/megalibft.h"
# include <stdio.h>
# include <math.h>
typedef struct		s_path
{
	char			**valid;
	struct s_path	*next;
}					t_path;

typedef struct		s_link
{
	struct s_room	*room;
	int				dist;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	t_link			*link;
	struct s_room	*next;
}					t_room;

typedef struct		s_lem
{
	t_room			*room;
	t_path			*path;
	int				ants;
	int				sflag;
	int				eflag;
	char			*start;
	char			*end;
	int				room_size;
	char			***pathz;
	int				namelen;
	int				pathid;
	int				aryid;
}					t_lem;
/*
** -------------------------------- validation.c ----------------------------
*/
int         valid_room(t_lem *lem, char *a, char *b);
void		check_format(t_lem *lem, char *str);
void		check_startend(t_lem *lem, char *str);
int        	check_xy_format(char *str);
/*
** -------------------------------- store.c ---------------------------------
*/
t_room		*room_store(t_lem *lem, char *line);
void		link_store(t_lem *lem, char *line);
t_link		*append_link(t_room *r1, t_room *r2, char *name);
/*
** -------------------------------- read.c ----------------------------------
*/
int		ant_count(t_lem *lem);
void	read_input(t_lem *lem);
/*
** -------------------------------- lemin.c ---------------------------------
*/
void print_struct(t_lem *lem);
int			error_handling(void);
/*
** -------------------------------- init.c ----------------------------------
*/
t_lem		*init_struct(void);
/*
** -------------------------------- pathing.c -------------------------------
*/
void init_pathz(t_lem *lem);
void start_path(t_lem *lem);
int		matching_room(t_lem *lem, char *room);
#endif
