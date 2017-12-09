/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:10:56 by evanheum          #+#    #+#             */
/*   Updated: 2017/12/09 14:17:46 by evanheum         ###   ########.fr       */
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
	int				flag;
	int				weight;
	int				len;
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
	int				ant;
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
t_path	*store_path(t_lem *lem, int len, char **rlist);
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
void	print_list(t_lem *lem, char **ary, int len);
/*
** -------------------------------- init.c ----------------------------------
*/
t_lem		*init_struct(void);
void ft_print2d(char **ary, int len);
/*
** -------------------------------- pathing.c -------------------------------
*/
int compare_path(t_path *path, t_path *p_next);
int		matching_room(t_lem *lem, char *room, char **rlist, int len);
void find_path(t_lem *lem, t_room *room, char **rlist, int len);
void start_path(t_lem *lem);
// void add_room(t_lem *lem, t_room *room, char **rlist, int len);
void shortest_paths(t_lem *lem);
void add_optimal_path(t_lem *lem);
void move_ants(t_lem *lem);
void	find_optimal_path(t_lem *lem);
/*
** -------------------------------- opt_pathing.c ----------------------------
*/

/*
** -------------------------------- free.c -----------------------------------
*/
void remove_paths(t_lem *lem);
#endif
