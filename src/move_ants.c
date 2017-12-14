/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:39:40 by evanheum          #+#    #+#             */
/*   Updated: 2017/12/13 11:30:02 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void		set_ant_paths(t_lem *lem)
{
	t_path	*path;
	t_ant	*ant;
	int		len;

	ant = lem->ant;
	len = lem->len;
	while (ant)
	{
		path = lem->path;
		while (path)
		{
			if (ant && path->len <= len)
			{
				ant->path = path;
				ant->len = len;
				ant = ant->next;
			}
			path = path->next;
		}
		len++;
	}
	move_ants(lem);
}

void		move_ants(t_lem *lem)
{
	int		end;
	t_ant	*ant;

	end = 0;
	while (end < lem->antcount)
	{
		ant = lem->ant;
		while (ant)
		{
			if (ant->len <= lem->len)
			{
				if (ant->path->valid[ant->i])
				{
					if (!ft_strcmp(ant->path->valid[ant->i], lem->end))
						end++;
					ft_printf("L%d-%s ", ant->ant, ant->path->valid[ant->i]);
					ant->i++;
				}
			}
			ant = ant->next;
		}
		ft_printf("\n");
		lem->len++;
	}
}
