/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:09:55 by evanheum          #+#    #+#             */
/*   Updated: 2017/11/16 16:35:02 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void print_struct(t_lem *lem)
{
	t_room	*room;
	t_link	*link;

	room = lem->room;
	// ft_printf("start: %s\nend: %s\n", lem->start, lem->end);
	while (room)
	{
		link = room->link;
		while (link)
		{
			ft_printf("room: %s\t linked: %s\n", room->name, link->room->name);
			link = link->next;
		}
		room = room->next;
	}
}

int error_handling(void)
{
	int i;

	i = 6;
	ft_printf( YELLOW "ERROR: INVALID FILE \n" END);
	sleep(1);
	ft_printf( CYAN "THIS PROGRAM WILL SELF DESTRUCT IN 5 SECONDS\n" END);
	sleep(1);
	while(--i > 0)
	{
		ft_printf(YELLOW "%d\t" END, i);
		sleep(1);
	}
	ft_printf(RED "BOOOOOOOM!!!\n" END);
	exit(0);
}

int		main(void)
{
	int i;

	i = 0;
	t_lem	*lem;
	lem = init_struct();
	ant_count(lem);
	read_input(lem);
	// ft_printf("%d\n", lem->room_size);
	start_path(lem);
	// print_struct(lem);
	// while (i < lem->room_size)
	// {
	// 	// ft_printf("%d\n",/ lem->aryid);
	// 	ft_printf("%s\n", lem->pathz[lem->aryid][i]);
	// 	i++;
	// }
}