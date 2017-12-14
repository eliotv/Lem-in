/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:42:37 by evanheum          #+#    #+#             */
/*   Updated: 2017/12/13 11:10:33 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void		print_struct(t_lem *lem)
{
	t_ant	*room;
	t_link	*link;

	room = lem->ant;
	while (room)
	{
		ft_printf("ant:%d\tlen:%d\tpath:%s\n", room->ant,
			room->len, room->path->valid[1]);
		room = room->next;
	}
}

void		print_path(t_lem *lem)
{
	t_path	*path;
	int		i;

	path = lem->path;
	while (path)
	{
		i = 0;
		while (path->valid[i])
		{
			ft_printf("%s\t", path->valid[i]);
			i++;
		}
		ft_printf("\n");
		ft_printf(RED"%d\n" END, path->len);
		path = path->next;
	}
}

void		print_read(t_lem *lem)
{
	t_read	*read;

	read = lem->read;
	while (read)
	{
		ft_printf("%s\n", read->str);
		read = read->next;
	}
	ft_printf("\n\n");
}

void		print_opt_path(t_lem *lem)
{
	t_path	*path;

	path = lem->path;
	while (path)
	{
		ft_print2d(path->valid, path->len);
		ft_printf(RED"%d\t"END BLUE"%d\n"END, path->weight, path->flag);
		path = path->next;
	}
}

void		ft_print2d(char **ary, int len)
{
	int		i;

	i = 0;
	while (i <= len)
	{
		ft_printf(YELLOW"%s\t" END, ary[i]);
		i++;
	}
}
