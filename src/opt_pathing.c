/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_pathing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 10:42:19 by evanheum          #+#    #+#             */
/*   Updated: 2017/12/13 14:20:47 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void		find_optimal_path(t_lem *lem)
{
	t_path	*path;
	t_path	*tmp;

	path = lem->path->next;
	tmp = lem->path;
	while (path)
	{
		if (path->weight >= tmp->weight && path->len <= tmp->len)
		{
			tmp = path;
		}
		path = path->next;
	}
	tmp->flag = 1;
	store_optimal_path(lem);
}

void		shortest_opt_path(t_lem *lem)
{
	t_path	*path;

	path = lem->path;
	if (path->next == NULL)
		lem->len = path->len;
	while (path->next)
	{
		if (lem->len == 0)
			lem->len = path->len;
		if (path->len > path->next->len)
			lem->len = path->next->len;
		path = path->next;
	}
	set_ant_paths(lem);
}

void		store_optimal_path(t_lem *lem)
{
	t_path	*opt;
	t_path	*tmp;
	t_path	*path;

	path = lem->path;
	opt = lem->path;
	tmp = NULL;
	while (opt->flag != 1)
		opt = opt->next;
	add_optimal_path(path, opt, tmp);
}

void		add_optimal_path(t_path *path, t_path *opt, t_path *tmp)
{
	while (path)
	{
		if (compare_path(opt, path) == 0)
		{
			if (!tmp)
			{
				path->flag = 1;
				tmp = path;
			}
			else if (compare_path(path, tmp) == 0)
			{
				path->flag = 1;
				tmp = path;
			}
			else if (path->len <= tmp->len)
			{
				tmp->flag = 0;
				path->flag = 1;
				tmp = path;
			}
		}
		path = path->next;
	}
}
