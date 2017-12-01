/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:30:55 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/30 17:12:04 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int		matching_room(t_lem *lem, char *room)
{
	int i;

	i = 0;
	if (lem->pathid == 0)
	{
		if (!ft_strcmp(lem->pathz[lem->aryid][i], room))
			return (-1);
	}
	else
	{
		while(i < lem->pathid)
		{
			if(!ft_strcmp(lem->pathz[lem->aryid][i], room))
				return (-1);
			i++;
		}
	}
	if(lem->pathid < lem->room_size)
		lem->pathid++;
	// else
	// {
	// 	lem->aryid++;
	// 	lem->pathid = 0;
	// }
	return (0);
}

void add_room(t_lem *lem, t_room *room)
{
	int i;

	i = 0;
	while (i < lem->pathid)
	{
		if (lem->pathz[lem->aryid][i][0] == '\0')
		{
			ft_strncpy(lem->pathz[lem->aryid][i], room->name, ft_strlen(room->name));
			ft_printf("%d\t%s\n", lem->pathid, lem->pathz[lem->aryid][i]);
		}
		i++;
	}
	// if (!ft_strcmp(room->name, lem->end))
	// {
	// 	lem->aryid++;
	// 	lem->pathid = 0;
	// }
		//return the 2d array the holds the valid path
}

void find_path(t_lem *lem, t_room *room)
{
	while(room->link)
	{
		if (matching_room(lem, room->link->room->name) == 0)
		{
			add_room(lem, room);
			find_path(lem ,room->link->room);
		}
		room->link = room->link->next;
	}
	// ft_printf("1\n");
	// lem->aryid++;
}

void start_path(t_lem *lem)
{
	t_room *room;

	room = lem->room;
	while (room->next && ft_strcmp(room->name, lem->start))
		room = room->next;
	init_pathz(lem);
	find_path(lem, room);
}

void init_pathz(t_lem *lem)
{
	int i;
	int j;
	
	i = 0;
	if (!(lem->pathz = (char***)malloc(sizeof(char**) * lem->room_size)))
		return ;
	while (i < lem->room_size)
	{
		j = 0;
		if(!(lem->pathz[i] = (char**)malloc(sizeof(char*) * lem->room_size)))
			return ;
		while (j < lem->room_size)
		{
			if(!(lem->pathz[i][j] = (char*)malloc(sizeof(char) * lem->namelen + 1)))
				return ;
			ft_memset(lem->pathz[i][j], lem->namelen + 1, '\0');
			// ft_strncpy(lem->pathz[i][j], "123", lem->namelen);
			// ft_printf("%s\n",lem->pathz[i][j]);
			j++;
		}
		// ft_printf("\n");
		i++;
	}
}