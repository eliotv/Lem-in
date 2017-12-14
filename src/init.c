/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:59:14 by evanheum          #+#    #+#             */
/*   Updated: 2017/12/13 10:18:38 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

t_lem		*init_struct(void)
{
	t_lem	*lem;

	lem = (t_lem*)malloc(sizeof(t_lem));
	lem->antcount = 0;
	lem->sflag = 0;
	lem->eflag = 0;
	lem->start = "\0";
	lem->end = "\0";
	lem->room = NULL;
	lem->path = NULL;
	lem->ant = NULL;
	lem->read = NULL;
	lem->room_size = 0;
	lem->namelen = 0;
	lem->pathid = 1;
	lem->aryid = 0;
	lem->len = 0;
	return (lem);
}

void		free_2darray(t_path *path)
{
	int		i;

	i = 0;
	while (path->valid[i])
	{
		ft_strdel(&path->valid[i]);
		i++;
	}
	free(path->valid);
}
