/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:09:55 by evanheum          #+#    #+#             */
/*   Updated: 2017/12/07 13:45:17 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

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
	t_lem	*lem;
	lem = init_struct();
	ant_count(lem);
	read_input(lem);
	// ft_printf("%d\n", lem->room_size);
	start_path(lem);
	// print_struct(lem);
	// print_path(lem);
	shortest_paths(lem);
	return (0);
}



// void shortest_paths(t_lem *lem)
// {
// 	t_path *path;
// 	t_path *p_next;
// 	int len;
// 	int i;

// 	len = 0;
// 	path = lem->path;
// 	while (path)
// 	{
// 		p_next = lem->path;
// 		while(p_next)
// 		{
// 			if (compare_path(path, p_next) == 0)
// 			{
// 				path->weight++;
// 				p_next->weight++;
// 			}
// 			else
// 			{
// 				p_next->weight+= ((path->len >=  p_next->len) ? 1 : 0);
// 				path->weight += ((path->len <= p_next->len) ? 1 : 0);
// 			} 
// 			p_next = p_next->next;
// 		}
// 		path = path->next;
// 	}
// 	path = lem->path;
// 	find_optimal_path(lem);
// 	add_optimal_path(lem);
// 	while (path)
// 	{
// 		ft_print2d(path->valid, path->len);
// 		ft_printf(RED"%d\t"END BLUE"%d\n"END, path->weight, path->flag);
// 		path = path->next;
// 	}
// }


// void add_optimal_path(t_lem *lem)
// {
// 	t_path *path;
// 	t_path *opt;
// 	t_path *tmp;

// 	tmp = NULL;
// 	opt = lem->path;
// 	while (opt->flag != 1)
// 		opt = opt->next;
// 	path = lem->path;
// 	while (path)
// 	{
// 		if (compare_path(opt, path) == 0)
// 		{
// 			if (!tmp)
// 			{
// 				path->flag = 1;
// 				tmp = path;
// 			}
// 			else if((compare_path(path, tmp) == 0) && path->weight >= tmp->weight)
// 			{
// 				tmp = path;
// 				tmp->flag = 1;
// 			}
// 		}
// 		path = path->next;
// 	}
// }