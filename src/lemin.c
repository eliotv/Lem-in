/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:09:55 by evanheum          #+#    #+#             */
/*   Updated: 2017/12/13 09:08:32 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void	print_read(t_lem *lem)
{
	t_read *read;

	read = lem->read;
	while (read)
	{
		ft_printf("%s\n", read->str);
		read = read->next;
	}
	ft_printf("\n\n");
}

void print_path(t_lem *lem)
{
	t_path *path;

	path = lem->path;
	while(path)
	{
		int i = 0;
		while(path->valid[i])
		{
			ft_printf("%s\t", path->valid[i]);
			i++;
		}
		ft_printf("\n");
		ft_printf(RED"%d\n" END, path->len);
		path = path->next;
	}
}

void print_struct(t_lem *lem)
{
	t_ant	*room;
	t_link	*link;

	room = lem->ant;
	while (room)
	{
			ft_printf("ant:%d\tlen:%d\tpath:%s\n", room->ant, room->len,room->path->valid[1]);
		room = room->next;
	}
}

int error_handling(char *str)
{
	int i;

	i = 6;
	ft_printf( YELLOW "ERROR: %s\n" END, str);
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
	// t_path *path;
	t_lem	*lem;
	
	lem = init_struct();
	ant_count(lem);
	read_input(lem);
	start_path(lem);
	remove_paths(lem);
	// print_read(lem);
	shortest_opt_path(lem);
	free_ant(lem);
	free_str(lem);
	free_roomlink(lem);
	free_paths(lem);
	free(lem);
	// print_struct(lem);
	// path = lem->path;
	// while (path)
	// {
	// 	ft_print2d(path->valid, path->len);
	// 	ft_printf(RED"%d\t"END BLUE"%d\n"END, path->weight, path->flag);
	// 	path = path->next;
	// }
	return (0);
}