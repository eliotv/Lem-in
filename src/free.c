/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 10:00:34 by evanheum          #+#    #+#             */
/*   Updated: 2017/12/13 10:17:54 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void		remove_paths(t_lem *lem)
{
	t_path	*cur;
	t_path	*prev;
	t_path	*tmp;

	if (!lem->path)
		return ;
	while (lem->path->flag != 1 && lem->path)
	{
		tmp = lem->path;
		lem->path = lem->path->next;
		free_2darray(tmp);
		free(tmp);
	}
	cur = lem->path;
	while (cur)
	{
		while (cur->next && cur->next->flag == 0)
		{
			tmp = cur->next;
			cur->next = tmp->next;
			free_2darray(tmp);
			free(tmp);
		}
		cur = cur->next;
	}
}

void		free_paths(t_lem *lem)
{
	t_path	*path;
	t_path	*tmp;

	if (!lem->path)
		return ;
	path = lem->path;
	while (path)
	{
		tmp = path->next;
		free_2darray(path);
		free(path);
		path = tmp;
	}
}

void		free_str(t_lem *lem)
{
	t_read	*read;
	t_read	*tmp;

	if (!lem->read)
		return ;
	read = lem->read;
	while (read)
	{
		tmp = read->next;
		ft_strdel(&read->str);
		free(read);
		read = tmp;
	}
	if (lem->room)
		free_roomlink(lem);
}

void		free_ant(t_lem *lem)
{
	t_ant	*tmp;

	if (!lem->ant)
		return ;
	while (lem->ant)
	{
		tmp = lem->ant;
		lem->ant = lem->ant->next;
		free(tmp);
	}
	if (lem->read)
		free_str(lem);
}

void		free_roomlink(t_lem *lem)
{
	t_link	*link;
	t_room	*room;
	t_room	*tmp;
	t_link	*temp;

	room = lem->room;
	while (room)
	{
		tmp = room->next;
		ft_strdel(&room->name);
		link = room->link;
		while (link)
		{
			temp = link->next;
			free(link);
			link = temp;
		}
		free(room);
		room = tmp;
	}
	if (lem->path)
		free_paths(lem);
}
