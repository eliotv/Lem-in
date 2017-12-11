/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:09:55 by evanheum          #+#    #+#             */
/*   Updated: 2017/12/11 13:41:45 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void	print_list(t_lem *lem, char **ary, int len)
{
	int i;

	i = 0;
	while (i <= len)
	{
		ft_printf("%s ", ary[i]);
		i++;
	}
	ft_putchar('\n');
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
	t_room	*room;
	t_link	*link;

	room = lem->room;
	// ft_printf("start: %s\nend: %s\n", lem->start, lem->end);
	while (room)
	{
		// link = room->link;
		// while (link)
		// {
		if (room->ant > 0)
			ft_printf("L%s-%d ", room->name, room->ant);
			// link = link->next;
		// }
		room = room->next;
	}
	ft_printf("\n");
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
	// t_path *path;
	t_lem	*lem;

	lem = init_struct();
	ant_count(lem);
	read_input(lem);
	start_path(lem);
	// print_path(lem);
	shortest_paths(lem);
	find_optimal_path(lem);
	add_optimal_path(lem);
	remove_paths(lem);
	shortest_opt_path(lem);
	// move_ants(lem);
	// print_struct(lem);
	// path = lem->path;
	// while (path)
	// {
	// 	ft_print2d(path->valid, path->len);
	// 	ft_printf(RED"%d\t"END BLUE"%d\n"END, path->weight, path->flag);
	// 	path = path->next;
	// }
	// ft_printf("%d\n", lem->len);
	return (0);
}