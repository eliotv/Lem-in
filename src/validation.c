/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 09:28:22 by evanheum          #+#    #+#             */
/*   Updated: 2017/12/14 16:17:03 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void		check_startend(t_lem *lem, char *str)
{
	if (lem->sflag == 1)
	{
		lem->start = str;
		lem->sflag++;
	}
	else if (lem->eflag == 1)
	{
		lem->end = str;
		lem->eflag++;
	}
	else
		error_handling(lem, "Invalid number or starts or endings");
}

void		check_format(t_lem *lem, char *str)
{
	int		link;
	int		room;
	int		i;
	t_room	*tmp;

	i = 0;
	room = 0;
	link = 0;
	while (str[i])
	{
		if (str[i] == '-')
			link = 1;
		else if (str[i] == ' ')
			room++;
		i++;
	}
	if (room == 2)
		lem->room = room_store(lem, str);
	else if (link == 1)
		link_store(lem, str);
	else if (room != 2 || link != 1)
		error_handling(lem, "Invalid room or link");
}

int			valid_room(t_lem *lem, char *a, char *b)
{
	int		flag;
	t_room	*tmp;

	tmp = lem->room;
	flag = 0;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, a))
			flag++;
		else if (!ft_strcmp(tmp->name, b))
			flag++;
		tmp = tmp->next;
	}
	return (flag);
}

int			check_xy_format(char *str)
{
	t_room	*room;
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (0);
}

void		link_compare(t_lem *lem, char *s1, char *s2)
{
	t_room	*room;
	t_link	*link;

	room = lem->room;
	while (room && ft_strcmp(s1, room->name))
		room = room->next;
	link = room->link;
	while (link)
	{
		if (!ft_strcmp(s2, link->room->name))
			error_handling(lem, "link already exists");
		link = link->next;
	}
}
