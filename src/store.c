/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:13:23 by evanheum          #+#    #+#             */
/*   Updated: 2017/12/14 13:58:25 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

t_path		*store_path(t_lem *lem, int len, char **rlist)
{
	t_path	*new;
	t_path	*tmp;
	int		i;

	i = 0;
	tmp = lem->path;
	if (!(new = malloc(sizeof(t_path))))
		return (NULL);
	new->valid = (char**)malloc(sizeof(char*) * lem->room_size + 1);
	new->len = len;
	new->weight = 0;
	new->flag = 0;
	while (i <= len)
	{
		new->valid[i] = ft_strdup(rlist[i]);
		i++;
	}
	new->next = NULL;
	if (!tmp)
		return (new);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (lem->path);
}

t_link		*append_link(t_room *r1, t_room *r2, char *name)
{
	t_link	*link;
	t_link	*new;

	while (r2->next && ft_strcmp(name, r2->name))
		r2 = r2->next;
	if (!(new = malloc(sizeof(t_link))))
		return (NULL);
	new->room = r2;
	new->next = NULL;
	if (!r1->link)
		return (new);
	link = r1->link;
	while (link->next)
	{
		if (!ft_strcmp(link->room->name, name))
			return (r1->link);
		link = link->next;
	}
	if (ft_strcmp(link->room->name, name))
		link->next = new;
	return (r1->link);
}

void		link_store(t_lem *lem, char *line)
{
	char	**str;
	char	*r1;
	char	*r2;
	t_room	*room;

	str = ft_strsplit(line, '-');
	if (valid_room(lem, str[0], str[1]) != 2)
		error_handling(lem, "Invalid link to room");
	r1 = str[0];
	r2 = str[1];
	room = lem->room;
	while (room)
	{
		if (!ft_strcmp(r1, room->name))
			room->link = append_link(room, lem->room, r2);
		else if (!ft_strcmp(r2, room->name))
			room->link = append_link(room, lem->room, r1);
		room = room->next;
	}
	free(str[0]);
	free(str[1]);
	free(str);
}

t_room		*room_store(t_lem *lem, char *line)
{
	char	**str;
	t_room	*tmp;
	t_room	*new;

	(line[0] == 'L') ? error_handling(lem, "L is invalid file format") : 0;
	if (!(new = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	str = ft_strsplit(line, ' ');
	free(str[1]);
	free(str[2]);
	(lem->sflag == 1 || lem->eflag == 1) ? check_startend(lem, str[0]) : 0;
	new->name = str[0];
	if (check_xy_format(str[1]) && check_xy_format(str[2]))
		error_handling(lem, "Invalid link given");
	new->link = NULL;
	new->next = NULL;
	lem->room_size++;
	free(str);
	tmp = lem->room;
	if (tmp == NULL)
		return (new);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (lem->room);
}

t_ant		*store_ants(t_lem *lem, int i)
{
	t_ant	*ant;
	t_ant	*new;

	if (!(new = (t_ant*)malloc(sizeof(t_ant))))
		return (NULL);
	new->ant = i;
	new->i = 1;
	new->next = NULL;
	if (!lem->ant)
		return (new);
	ant = lem->ant;
	while (ant->next)
		ant = ant->next;
	ant->next = new;
	return (lem->ant);
}
