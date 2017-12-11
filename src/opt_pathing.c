/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_pathing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 10:42:19 by evanheum          #+#    #+#             */
/*   Updated: 2017/12/11 13:42:51 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int add_ant (t_lem *lem, int ant)
{
	t_path *path;
	int		i;
	i = 1;
	path = lem->path;
	while (path)
	{
		if (path->len <= lem->len && ant < lem->ants)
		{
			// place_ant(lem, path->valid[1], ant);
			if (place_ant(lem, path->valid[i], ant) == 0)
				ant++;
			
		}
		path = path->next;
	}
	i++;
	return (ant);
}


int place_ant(t_lem *lem, char *name, int ant)
{
	t_room *room;

	room = lem->room;
	while (ft_strcmp(room->name, name) && room)
		room = room->next;
	if (room->ant == 0)
	{
		room->ant = ant;
		return 0;
	}
	return -1;
}

void push_ants(t_lem *lem)
{
	t_link *link;
	t_room *room;
	
	room = lem->room;
	while (room)
	{
		if (room->ant != 0)
		{
			find_next_room(lem->path, room);
			//compare rooms find next room
		}
	}
}

void move_ants(t_lem *lem)
{
	int end;
	int	i;
	i = 0;
	// while (end < lem->ants)
	// {
		if (i < lem->ants)
		{
			i++;
			i = add_ant(lem, i);
			// lem->len++;
		}
		print_struct(lem);
		push_ants(lem);
		
	// }
}

void shortest_opt_path(t_lem *lem)
{
	t_path *path;

	path = lem->path;
	if (path->next == NULL)
		lem->len = path->len;
	while (path->next)
	{
		if (lem->len == 0)
			lem->len = path->len;
		if(path->len > path->next->len)
			lem->len = path->next->len;
		path = path->next;
	}
}

void find_next_room(t_path *path, t_room *room)
{
	t_path *p;
	t_room *r;
	int i;

	r = room;
	p = path;
	while (p)
	{
		i = 1;
		while (p->valid[i])
		{
			if (ft_strcmp(p->valid[i], r->name))
			{
				
			}
			i++;

		}
		
	}
}