/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:30:55 by evanheum          #+#    #+#             */
/*   Updated: 2017/12/14 14:01:30 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int			compare_path(t_path *path, t_path *p_next)
{
	int		i;
	int		j;

	i = 1;
	while (i < path->len)
	{
		j = 1;
		while (j < p_next->len)
		{
			if (!ft_strcmp(path->valid[i], p_next->valid[j]))
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int			matching_room(t_lem *lem, char *room, char **rlist, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (!ft_strcmp(rlist[i], room))
			return (-1);
		i++;
	}
	return (0);
}

void		find_path(t_lem *lem, t_room *room, char **rlist, int len)
{
	t_link	*link;

	rlist[len] = ft_strdup(room->name);
	if (!ft_strcmp(room->name, lem->end))
	{
		lem->path = store_path(lem, len, rlist);
		ft_strdel(&rlist[len]);
		return ;
	}
	link = room->link;
	while (link)
	{
		if (matching_room(lem, link->room->name, rlist, len) == 0)
			find_path(lem, link->room, rlist, len + 1);
		link = link->next;
	}
	ft_strdel(&rlist[len]);
}

void		start_path(t_lem *lem)
{
	char	**roomlist;
	t_room	*room;

	room = lem->room;
	while (room->next && ft_strcmp(room->name, lem->start))
		room = room->next;
	if (!(roomlist = (char**)malloc(sizeof(char*) * lem->room_size)))
		return ;
	find_path(lem, room, roomlist, 0);
	free(roomlist);
	if (!lem->path)
		error_handling(lem, "No valid paths");
	shortest_paths(lem);
}

void		shortest_paths(t_lem *lem)
{
	t_path	*path;
	t_path	*p_next;
	int		len;

	len = 0;
	path = lem->path;
	while (path)
	{
		p_next = lem->path;
		while (p_next)
		{
			if (compare_path(path, p_next) == 0)
			{
				path->weight++;
				p_next->weight++;
			}
			else
			{
				p_next->weight += ((path->len >= p_next->len) ? 1 : 0);
				path->weight += ((path->len <= p_next->len) ? 1 : 0);
			}
			p_next = p_next->next;
		}
		path = path->next;
	}
}
