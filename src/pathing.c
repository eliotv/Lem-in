/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:30:55 by evanheum          #+#    #+#             */
/*   Updated: 2017/12/07 13:47:09 by evanheum         ###   ########.fr       */
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


int		matching_room(t_lem *lem, char *room, char **rlist, int len)
{
	int i;

	i = 0;
	while(i < len)
	{
		if(!ft_strcmp(rlist[i], room))
			return (-1);
		i++;
	}
	return (0);
}
void find_path(t_lem *lem, t_room *room, char **rlist, int len)
{
	t_link *link;

	rlist[len] = ft_strdup(room->name);
	if (!ft_strcmp(room->name, lem->end))
	{
		lem->path = store_path(lem, len, rlist);
		ft_strdel(&rlist[len]);
		return ;	
	}
	link = room->link;
	while(link)
	{
		if (matching_room(lem, link->room->name, rlist, len) == 0)
			find_path(lem ,link->room, rlist, len + 1);
		link = link->next;
	}
	ft_strdel(&rlist[len]);
}

void start_path(t_lem *lem)
{
	char	**roomlist;
	t_room *room;

	room = lem->room;
	while (room->next && ft_strcmp(room->name, lem->start))
		room = room->next;
	if(!(roomlist = (char**)malloc(sizeof(char*) * lem->room_size)))
		return ;
	find_path(lem, room , roomlist, 0);
	
}

void	find_optimal_path(t_lem *lem)
{
	t_path *path;
	t_path *tmp;

	path = lem->path->next;
	tmp = lem->path;
	while (path)
	{
		if (path->weight > tmp->weight)
		{
			tmp = path;
		}
		path = path->next;
	}
	tmp->flag = 1;
}

void shortest_paths(t_lem *lem)
{
	t_path *path;
	t_path *p_next;
	int len;
	int i;

	len = 0;
	path = lem->path;
	while (path)
	{
		p_next = lem->path;
		while(p_next)
		{
			if (compare_path(path, p_next) == 0)
			{
				path->weight++;
				p_next->weight++;
			}
			else
			{
				p_next->weight+= ((path->len >=  p_next->len) ? 1 : 0);
				path->weight += ((path->len <= p_next->len) ? 1 : 0);
			} 
			p_next = p_next->next;
		}
		path = path->next;
	}
	path = lem->path;
	find_optimal_path(lem);
	add_optimal_path(lem);
	while (path)
	{
		ft_print2d(path->valid, path->len);
		ft_printf(RED"%d\t"END BLUE"%d\n"END, path->weight, path->flag);
		path = path->next;
	}
}

void add_optimal_path(t_lem *lem)
{
	t_path *path;
	t_path *opt;
	t_path *tmp;

	tmp = NULL;
	opt = lem->path;
	while (opt->flag != 1)
		opt = opt->next;
	path = lem->path;
	while (path)
	{
		if (compare_path(opt, path) == 0)
		{
			if (!tmp)
			{
				path->flag = 1;
				tmp = path;
			}
			else if((compare_path(path, tmp) == 0) && path->weight >= tmp->weight)
			{
				tmp = path;
				tmp->flag = 1;
			}
		}
		path = path->next;
	}
}